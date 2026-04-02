use eframe::egui;
use egui_plot::{Line, Plot, PlotPoints};
use serde::Deserialize;
use std::collections::VecDeque;
use std::sync::mpsc::{self, Receiver};
use std::thread;
use std::time::{Duration, Instant};
use sysinfo::{CpuRefreshKind, MemoryRefreshKind, RefreshKind, System};
use wmi::{COMLibrary, WMIConnection};

// The structure that WMI will deserialize LHM sensor data into
#[derive(Deserialize, Debug, Clone)]
#[serde(rename_all = "PascalCase")]
struct LhmSensor {
    name: String,
    sensor_type: String,
    value: f32,
}

fn main() -> Result<(), eframe::Error> {
    let options = eframe::NativeOptions {
        viewport: egui::ViewportBuilder::default().with_inner_size([650.0, 550.0]),
        ..Default::default()
    };

    eframe::run_native(
        "Ryzen APU Hardware Monitor",
        options,
        Box::new(|_cc| Ok(Box::new(TempMonitorApp::new()))),
    )
}

struct TempMonitorApp {
    sys: System,
    start_time: Instant,
    
    // Telemetry history for plotting
    cpu_usage_history: VecDeque<[f64; 2]>,
    ram_usage_history: VecDeque<[f64; 2]>,
    apu_temp_history: VecDeque<[f64; 2]>,
    
    // WMI Background Thread Channel
    wmi_receiver: Receiver<Vec<LhmSensor>>,
    latest_sensors: Vec<LhmSensor>,
}

impl TempMonitorApp {
    fn new() -> Self {
        // Only refresh CPU usage and Memory to keep overhead low
        let refreshes = RefreshKind::new()
            .with_cpu(CpuRefreshKind::new().with_cpu_usage())
            .with_memory(MemoryRefreshKind::new().with_ram());
        let sys = System::new_with_specifics(refreshes);

        // Setup the background thread for WMI to prevent GUI stuttering
        let (wmi_sender, wmi_receiver) = mpsc::channel();
        
        thread::spawn(move || {
            // Initialize COM library for this background thread
            let com_con = match COMLibrary::new() {
                Ok(c) => c,
                Err(_) => return, // Fail silently if COM fails
            };
            
            // Loop indefinitely, polling WMI every 1 second
            loop {
                // Connect to LibreHardwareMonitor's WMI namespace
                if let Ok(wmi_con) = WMIConnection::with_namespace_path("ROOT\\LibreHardwareMonitor", com_con) {
                    let query = "SELECT Name, SensorType, Value FROM Sensor WHERE SensorType = 'Temperature' OR SensorType = 'Power'";
                    if let Ok(results) = wmi_con.raw_query::<LhmSensor>(query) {
                        let _ = wmi_sender.send(results);
                    }
                }
                thread::sleep(Duration::from_secs(1));
            }
        });

        Self {
            sys,
            start_time: Instant::now(),
            cpu_usage_history: VecDeque::with_capacity(60),
            ram_usage_history: VecDeque::with_capacity(60),
            apu_temp_history: VecDeque::with_capacity(60),
            wmi_receiver,
            latest_sensors: Vec::new(),
        }
    }

    fn push_history(history: &mut VecDeque<[f64; 2]>, time: f64, value: f64) {
        if history.len() >= 60 {
            history.pop_front();
        }
        history.push_back([time, value]);
    }
}

impl eframe::App for TempMonitorApp {
    fn update(&mut self, ctx: &egui::Context, _frame: &mut eframe::Frame) {
        let elapsed = self.start_time.elapsed().as_secs_f64();

        // 1. Update standard system stats
        self.sys.refresh_cpu_usage();
        self.sys.refresh_memory();

        let global_cpu_usage = self.sys.global_cpu_info().cpu_usage() as f64;
        let ram_used_gb = self.sys.used_memory() as f64 / 1_073_741_824.0;

        Self::push_history(&mut self.cpu_usage_history, elapsed, global_cpu_usage);
        Self::push_history(&mut self.ram_usage_history, elapsed, ram_used_gb);

        // 2. Fetch non-blocking WMI data from the background thread
        if let Ok(sensors) = self.wmi_receiver.try_recv() {
            self.latest_sensors = sensors;
        }

        // Try to find the APU Core Temperature (Tctl/Tdie) from LHM data
        let mut apu_temp = 0.0;
        for sensor in &self.latest_sensors {
            // "Core (Tctl/Tdie)" is the standard LHM name for AMD Zen temperatures
            if sensor.name.contains("Tctl") || sensor.name.contains("Core") && sensor.sensor_type == "Temperature" {
                apu_temp = sensor.value as f64;
                break;
            }
        }
        if apu_temp > 0.0 {
            Self::push_history(&mut self.apu_temp_history, elapsed, apu_temp);
        }

        // 3. Render the UI
        egui::CentralPanel::default().show(ctx, |ui| {
            ui.heading("Ryzen 9 7940HS APU Telemetry");
            ui.separator();

            if self.latest_sensors.is_empty() {
                ui.label(egui::RichText::new("⚠ LibreHardwareMonitor not detected.")
                    .color(egui::Color32::LIGHT_RED)
                    .strong());
                ui.label("Run LibreHardwareMonitor as Admin in the background to enable advanced APU telemetry (Tctl/Tdie, Wattage).");
                ui.separator();
            }

            // --- PLOT 1: APU Temperature ---
            ui.heading("🌡 APU Temperature (Tctl/Tdie)");
            ui.label(format!("Current: {:.1} °C", apu_temp));
            
            let temp_line = Line::new(PlotPoints::from_iter(self.apu_temp_history.iter().copied()))
                .color(egui::Color32::LIGHT_RED)
                .fill(0.0)
                .name("APU Temp (°C)");

            Plot::new("temp_plot")
                .view_aspect(4.0)
                .allow_drag(false)
                .allow_scroll(false)
                .include_y(0.0)
                .include_y(100.0) // Typical max temp for Zen 4
                .show(ui, |plot_ui| plot_ui.line(temp_line));

            ui.add_space(10.0);

            // --- PLOT 2: CPU Utilization ---
            ui.heading("⚙ CPU Utilization");
            ui.label(format!("Current: {:.1}%", global_cpu_usage));
            
            let cpu_line = Line::new(PlotPoints::from_iter(self.cpu_usage_history.iter().copied()))
                .color(egui::Color32::LIGHT_BLUE)
                .fill(0.0)
                .name("CPU Usage (%)");

            Plot::new("cpu_plot")
                .view_aspect(4.0)
                .allow_drag(false)
                .allow_scroll(false)
                .include_y(0.0)
                .include_y(100.0)
                .show(ui, |plot_ui| plot_ui.line(cpu_line));

            ui.add_space(10.0);

            // --- PLOT 3: RAM Usage ---
            let total_ram_gb = self.sys.total_memory() as f64 / 1_073_741_824.0;
            ui.heading("💾 System Memory");
            ui.label(format!("Used: {:.2} GB / {:.2} GB", ram_used_gb, total_ram_gb));

            let ram_line = Line::new(PlotPoints::from_iter(self.ram_usage_history.iter().copied()))
                .color(egui::Color32::LIGHT_GREEN)
                .fill(0.0)
                .name("RAM Usage (GB)");

            Plot::new("ram_plot")
                .view_aspect(4.0)
                .allow_drag(false)
                .allow_scroll(false)
                .include_y(0.0)
                .include_y(total_ram_gb)
                .show(ui, |plot_ui| plot_ui.line(ram_line));
        });

        // Request a repaint to keep the graphs flowing smoothly
        ctx.request_repaint_after(Duration::from_millis(500));
    }
}
