use eframe::egui;
use sysinfo::{Components, System};

fn main() -> Result<(), eframe::Error> {
    // Configure the initial window size
    let options = eframe::NativeOptions {
        viewport: egui::ViewportBuilder::default().with_inner_size([450.0, 350.0]),
        ..Default::default()
    };
    
    eframe::run_native(
        "Hardware Sensor Monitor",
        options,
        Box::new(|_cc| Ok(Box::new(TempMonitorApp::default()))),
    )
}

struct TempMonitorApp {
    sys: System,
    components: Components,
}

impl Default for TempMonitorApp {
    fn default() -> Self {
        let sys = System::new_all();
        // Fetches the initial list of available hardware sensors
        let components = Components::new_with_refreshed_list(); 
        Self { sys, components }
    }
}

impl eframe::App for TempMonitorApp {
    fn update(&mut self, ctx: &egui::Context, _frame: &mut eframe::Frame) {
        // Refresh the sensor data on every frame
        self.components.refresh();
        self.sys.refresh_memory();

        egui::CentralPanel::default().show(ctx, |ui| {
            ui.heading("Hardware Monitor (Windows 11)");
            ui.separator();
            
            // Warning label for Admin rights
            ui.label(egui::RichText::new("⚠ You MUST run this as Administrator to read CPU/GPU temperatures.")
                .color(egui::Color32::YELLOW)
                .strong());
            ui.separator();

            ui.heading("🌡 Component Temperatures");
            let mut found_temp = false;
            
            // Iterate through all discovered thermal zones
            for component in self.components.list() {
                found_temp = true;
                ui.label(format!("{}: {:.1} °C", component.label(), component.temperature()));
            }
            
            if !found_temp {
                ui.label(egui::RichText::new("No temperature sensors detected.")
                    .color(egui::Color32::LIGHT_RED));
                ui.label("If you are running as Admin, your motherboard's WMI thermal zones might be locked or unsupported by native APIs.");
            }

            ui.separator();
            ui.heading("💾 System Memory (RAM)");
            
            // Convert bytes to Megabytes for readability
            ui.label(format!(
                "Used: {} MB / Total: {} MB",
                self.sys.used_memory() / 1_048_576,
                self.sys.total_memory() / 1_048_576
            ));
            
            ui.label("RAM Temperature: N/A (No physical thermistors on consumer RAM)");
        });

        // Request a UI repaint every 1 second to keep stats continuously updating
        // without burning CPU cycles rendering static frames.
        ctx.request_repaint_after(std::time::Duration::from_secs(1));
    }
}
