mod hardware;

use eframe::egui;
use egui_plot::{Line, Plot, PlotPoints};
use serde::Deserialize;
use std::collections::VecDeque;
use std::sync::mpsc::{self, Receiver};
use std::time::{Duration, Instant};
use hardware::{HardwareProvider, RealHardware};
#[cfg(windows)]
use wmi::{COMLibrary, WMIConnection};
use hecs::World;

// --- ECS Components ---
struct MetricName(String);
struct MetricValue(f64);
struct History(VecDeque<[f64; 2]>);
struct Unit(String);
struct PlotColor(egui::Color32);
struct MaxY(f64);

#[cfg(windows)]
struct WmiFilter(Box<dyn Fn(&LhmSensor) -> bool + Send + Sync>);
struct ComponentFilter(Box<dyn Fn(&(String, f32)) -> bool + Send + Sync>);
struct DiskFilter(String);

#[derive(Deserialize, Debug, Clone)]
#[serde(rename_all = "PascalCase")]
struct LhmSensor {
    #[allow(dead_code)]
    name: String,
    #[allow(dead_code)]
    sensor_type: String,
    #[allow(dead_code)]
    value: f32,
}

fn main() -> Result<(), eframe::Error> {
    let args: Vec<String> = std::env::args().collect();
    let is_headless = args.contains(&"--headless".to_string());

    if is_headless {
        println!("Running in headless mode...");
        let mut app = HwMonitorApp::new(Box::new(RealHardware::new()));
        for i in 0..5 {
            println!("Tick {}...", i);
            app.tick(None);
            std::thread::sleep(Duration::from_millis(500));
        }
        println!("Headless execution successful.");
        return Ok(());
    }

    let options = eframe::NativeOptions {
        viewport: egui::ViewportBuilder::default().with_inner_size([900.0, 700.0]),
        ..Default::default()
    };

    eframe::run_native(
        "Advanced Hardware Monitor (ECS)",
        options,
        Box::new(|_cc| Ok(Box::new(HwMonitorApp::new(Box::new(RealHardware::new()))))),
    )
}

struct HwMonitorApp {
    world: World,
    hardware: Box<dyn HardwareProvider>,
    start_time: Instant,
    #[allow(dead_code)]
    wmi_receiver: Receiver<Vec<LhmSensor>>,
    is_dark_mode: bool,
    last_net_rx: u64,
    last_net_tx: u64,
}

impl HwMonitorApp {
    fn new(mut hardware: Box<dyn HardwareProvider>) -> Self {
        let mut world = World::new();
        
        hardware.refresh();
        let (initial_data, _, _) = hardware.collect_data(0, 0);

        // CPU Usage
        world.spawn((
            MetricName("01_CPU Utilization".to_string()),
            MetricValue(0.0),
            History(VecDeque::with_capacity(60)),
            Unit("%".to_string()),
            PlotColor(egui::Color32::LIGHT_BLUE),
            MaxY(100.0),
        ));

        // RAM Usage
        world.spawn((
            MetricName("02_System Memory".to_string()),
            MetricValue(0.0),
            History(VecDeque::with_capacity(60)),
            Unit("GB".to_string()),
            PlotColor(egui::Color32::LIGHT_GREEN),
            MaxY(initial_data.total_ram_gb),
        ));

        // Network Download
        world.spawn((
            MetricName("03_Network Download".to_string()),
            MetricValue(0.0),
            History(VecDeque::with_capacity(60)),
            Unit("MB/s".to_string()),
            PlotColor(egui::Color32::from_rgb(100, 200, 255)),
            MaxY(10.0),
        ));

        // Network Upload
        world.spawn((
            MetricName("04_Network Upload".to_string()),
            MetricValue(0.0),
            History(VecDeque::with_capacity(60)),
            Unit("MB/s".to_string()),
            PlotColor(egui::Color32::from_rgb(200, 100, 255)),
            MaxY(10.0),
        ));

        // APU Temperature
        let apu_temp_entity = world.spawn((
            MetricName("05_APU Temperature".to_string()),
            MetricValue(0.0),
            History(VecDeque::with_capacity(60)),
            Unit("°C".to_string()),
            PlotColor(egui::Color32::LIGHT_RED),
            MaxY(100.0),
        ));

        #[cfg(windows)]
        world.insert_one(apu_temp_entity, WmiFilter(Box::new(|s| {
            s.sensor_type == "Temperature" && (s.name == "Core (Tctl/Tdie)" || s.name.contains("CPU Package"))
        }))).unwrap();

        world.insert_one(apu_temp_entity, ComponentFilter(Box::new(|(label, _)| {
            let label = label.to_lowercase();
            label.contains("cpu") || label.contains("coretemp") || label.contains("tdie") || label.contains("package")
        }))).unwrap();

        // GPU Temperature
        let gpu_temp_entity = world.spawn((
            MetricName("06_GPU Temperature".to_string()),
            MetricValue(0.0),
            History(VecDeque::with_capacity(60)),
            Unit("°C".to_string()),
            PlotColor(egui::Color32::from_rgb(255, 165, 0)),
            MaxY(100.0),
        ));

        #[cfg(windows)]
        world.insert_one(gpu_temp_entity, WmiFilter(Box::new(|s| {
            s.sensor_type == "Temperature" && (s.name.contains("GPU Core") || s.name.contains("GPU Package"))
        }))).unwrap();
        
        #[cfg(not(windows))]
        let _ = gpu_temp_entity;

        // Disks
        for disk in &initial_data.disks {
            world.spawn((
                MetricName(format!("10_Disk ({})", disk.mount_point)),
                MetricValue(0.0),
                History(VecDeque::with_capacity(60)),
                Unit("GB".to_string()),
                PlotColor(egui::Color32::GRAY),
                MaxY(disk.total_gb),
                DiskFilter(disk.mount_point.clone()),
            ));
        }

        let (wmi_sender, wmi_receiver) = mpsc::channel();
        #[cfg(windows)]
        {
            std::thread::spawn(move || {
                loop {
                    if let Ok(com_con) = COMLibrary::new() {
                        loop {
                            match WMIConnection::with_namespace_path("ROOT\\LibreHardwareMonitor", com_con) {
                                Ok(wmi_con) => {
                                    loop {
                                        let query = "SELECT Name, SensorType, Value FROM Sensor WHERE SensorType = 'Temperature' OR SensorType = 'Power' OR SensorType = 'Load'";
                                        match wmi_con.raw_query::<LhmSensor>(query) {
                                            Ok(results) => {
                                                if wmi_sender.send(results).is_err() { return; }
                                            }
                                            Err(_) => break,
                                        }
                                        std::thread::sleep(Duration::from_secs(1));
                                    }
                                }
                                Err(_) => { std::thread::sleep(Duration::from_secs(3)); }
                            }
                        }
                    }
                    std::thread::sleep(Duration::from_secs(5));
                }
            });
        }
        #[cfg(not(windows))]
        let _ = wmi_sender;

        Self {
            world,
            hardware,
            start_time: Instant::now(),
            wmi_receiver,
            is_dark_mode: true,
            last_net_rx: 0,
            last_net_tx: 0,
        }
    }

    fn push_history(history: &mut History, time: f64, value: f64) {
        if history.0.len() >= 60 {
            history.0.pop_front();
        }
        history.0.push_back([time, value]);
    }

    fn tick(&mut self, ctx: Option<&egui::Context>) {
        let elapsed = self.start_time.elapsed().as_secs_f64();

        // 1. Hardware System
        self.hardware.refresh();
        let (data, net_rx, net_tx) = self.hardware.collect_data(self.last_net_rx, self.last_net_tx);
        self.last_net_rx = net_rx;
        self.last_net_tx = net_tx;

        for (_entity, (name, val, history)) in self.world.query_mut::<(&MetricName, &mut MetricValue, &mut History)>() {
            if name.0.contains("CPU Utilization") {
                val.0 = data.cpu_usage;
            } else if name.0.contains("System Memory") {
                val.0 = data.ram_used_gb;
            } else if name.0.contains("Network Download") {
                val.0 = data.net_rx_mb;
            } else if name.0.contains("Network Upload") {
                val.0 = data.net_tx_mb;
            } else {
                continue;
            }
            Self::push_history(history, elapsed, val.0);
        }

        // 2. Component System
        for (_entity, (filter, val, history)) in self.world.query_mut::<(&ComponentFilter, &mut MetricValue, &mut History)>() {
            for comp in &data.temps {
                if (filter.0)(comp) {
                    val.0 = comp.1 as f64;
                    Self::push_history(history, elapsed, val.0);
                    break;
                }
            }
        }

        // 3. WMI System
        #[cfg(windows)]
        {
            let mut latest_wmi_data = Vec::new();
            while let Ok(sensors) = self.wmi_receiver.try_recv() {
                latest_wmi_data = sensors;
            }
            if !latest_wmi_data.is_empty() {
                for (_entity, (filter, val, history)) in self.world.query_mut::<(&WmiFilter, &mut MetricValue, &mut History)>() {
                    for sensor in &latest_wmi_data {
                        if (filter.0)(sensor) {
                            val.0 = sensor.value as f64;
                            Self::push_history(history, elapsed, val.0);
                            break;
                        }
                    }
                }
            }
        }

        // 4. Disk System
        for (_entity, (filter, val, history)) in self.world.query_mut::<(&DiskFilter, &mut MetricValue, &mut History)>() {
            if let Some(disk) = data.disks.iter().find(|d| d.mount_point == filter.0) {
                val.0 = disk.used_gb;
                Self::push_history(history, elapsed, val.0);
            }
        }

        // 5. UI System (Only if context provided)
        if let Some(ctx) = ctx {
            if self.is_dark_mode { ctx.set_visuals(egui::Visuals::dark()); }
            else { ctx.set_visuals(egui::Visuals::light()); }

            egui::CentralPanel::default().show(ctx, |ui| {
                ui.horizontal(|ui| {
                    ui.heading("Advanced Hardware Monitor");
                    ui.with_layout(egui::Layout::right_to_left(egui::Align::Center), |ui| {
                        if ui.button(if self.is_dark_mode { "☀ Light" } else { "🌙 Dark" }).clicked() {
                            self.is_dark_mode = !self.is_dark_mode;
                        }
                    });
                });
                ui.separator();

                egui::ScrollArea::vertical().show(ui, |ui| {
                    egui::Grid::new("metrics_grid").num_columns(2).spacing([20.0, 20.0]).min_col_width(420.0).show(ui, |ui| {
                        let mut count = 0;
                        let mut query = self.world.query::<(&MetricName, &MetricValue, &History, &Unit, &PlotColor, &MaxY)>();
                        let mut entities: Vec<_> = query.into_iter().collect();
                        entities.sort_by(|a, b| a.1.0.0.cmp(&b.1.0.0));

                        for (_entity, (name, val, history, unit, color, max_y)) in entities {
                            ui.vertical(|ui| {
                                ui.horizontal(|ui| {
                                    let display_name = name.0.split('_').nth(1).unwrap_or(&name.0);
                                    ui.strong(display_name);
                                    ui.label(format!(": {:.2} {}", val.0, unit.0));
                                });
                                let values: Vec<f64> = history.0.iter().map(|p| p[1]).collect();
                                if !values.is_empty() {
                                    let min = values.iter().fold(f64::INFINITY, |a, &b| a.min(b));
                                    let max = values.iter().fold(f64::NEG_INFINITY, |a, &b| a.max(b));
                                    let avg = values.iter().sum::<f64>() / values.len() as f64;
                                    ui.label(egui::RichText::new(format!("Min: {:.1} | Max: {:.1} | Avg: {:.1}", min, max, avg)).size(11.0).weak());
                                }
                                let line = Line::new(PlotPoints::from_iter(history.0.iter().copied())).color(color.0).fill(0.0);
                                Plot::new(&name.0).view_aspect(3.5).allow_drag(false).allow_scroll(false).include_y(0.0).include_y(max_y.0).show(ui, |plot_ui| plot_ui.line(line));
                            });
                            count += 1;
                            if count % 2 == 0 { ui.end_row(); }
                        }
                    });
                });
            });
            ctx.request_repaint_after(Duration::from_millis(500));
        }
    }
}

impl eframe::App for HwMonitorApp {
    fn update(&mut self, ctx: &egui::Context, _frame: &mut eframe::Frame) {
        self.tick(Some(ctx));
    }
}

#[cfg(test)]
mod tests {
    use super::*;
    use hardware::MockHardware;

    #[test]
    fn test_push_history_limits() {
        let mut history = History(VecDeque::new());
        for i in 0..100 {
            HwMonitorApp::push_history(&mut history, i as f64, i as f64);
        }
        assert_eq!(history.0.len(), 60);
        assert_eq!(history.0.back().unwrap()[1], 99.0);
        assert_eq!(history.0.front().unwrap()[1], 40.0);
    }

    #[test]
    fn test_ecs_update_cycle() {
        let mock = Box::new(MockHardware {
            cpu: 45.0,
            ram: 12.0,
            net_rx: 5.5,
            net_tx: 1.2,
            temps: vec![("CPU Temperature".to_string(), 55.0)],
            disks: vec![hardware::DiskData {
                mount_point: "/".to_string(),
                used_gb: 100.0,
                total_gb: 500.0,
            }],
        });
        let mut app = HwMonitorApp::new(mock);
        
        app.tick(None);

        let mut found_cpu = false;
        let mut found_temp = false;
        let mut found_upload = false;
        let mut found_disk = false;
        for (_entity, (name, val)) in app.world.query_mut::<(&MetricName, &MetricValue)>() {
            if name.0.contains("CPU Utilization") {
                assert_eq!(val.0, 45.0);
                found_cpu = true;
            }
            if name.0.contains("APU Temperature") {
                assert_eq!(val.0, 55.0);
                found_temp = true;
            }
            if name.0.contains("Network Upload") {
                assert_eq!(val.0, 1.2);
                found_upload = true;
            }
            if name.0.contains("Disk (/)") {
                assert_eq!(val.0, 100.0);
                found_disk = true;
            }
        }
        assert!(found_cpu);
        assert!(found_temp);
        assert!(found_upload);
        assert!(found_disk);
    }
}
