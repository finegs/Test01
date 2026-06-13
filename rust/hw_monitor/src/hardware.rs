use sysinfo::{CpuRefreshKind, MemoryRefreshKind, RefreshKind, System, Disks, Networks, Components};

pub struct HardwareData {
    pub cpu_usage: f64,
    pub ram_used_gb: f64,
    pub total_ram_gb: f64,
    pub net_rx_mb: f64,
    pub temps: Vec<(String, f32)>,
}

pub trait HardwareProvider: Send + Sync {
    fn refresh(&mut self);
    fn collect_data(&self, last_net_total: u64) -> (HardwareData, u64);
}

pub struct RealHardware {
    sys: System,
    #[allow(dead_code)]
    disks: Disks,
    networks: Networks,
    components: Components,
}

impl RealHardware {
    pub fn new() -> Self {
        let refreshes = RefreshKind::new()
            .with_cpu(CpuRefreshKind::new().with_cpu_usage())
            .with_memory(MemoryRefreshKind::new().with_ram());
        let mut sys = System::new_with_specifics(refreshes);
        sys.refresh_all();
        
        let disks = Disks::new_with_refreshed_list();
        let networks = Networks::new_with_refreshed_list();
        let components = Components::new_with_refreshed_list();
        
        Self { sys, disks, networks, components }
    }
}

impl HardwareProvider for RealHardware {
    fn refresh(&mut self) {
        self.sys.refresh_cpu_usage();
        self.sys.refresh_memory();
        self.networks.refresh();
        self.components.refresh();
    }

    fn collect_data(&self, last_net_total: u64) -> (HardwareData, u64) {
        let cpu_usage = self.sys.global_cpu_info().cpu_usage() as f64;
        let ram_used_gb = self.sys.used_memory() as f64 / 1_073_741_824.0;
        let total_ram_gb = self.sys.total_memory() as f64 / 1_073_741_824.0;
        
        let mut net_rx = 0u64;
        for (_, data) in &self.networks {
            net_rx += data.received();
        }
        let net_rx_mb = if last_net_total > 0 {
            (net_rx.saturating_sub(last_net_total)) as f64 / 1_048_576.0
        } else { 0.0 };

        let temps = self.components.iter().map(|c| (c.label().to_string(), c.temperature())).collect();

        (HardwareData {
            cpu_usage,
            ram_used_gb,
            total_ram_gb,
            net_rx_mb,
            temps,
        }, net_rx)
    }
}

#[cfg(test)]
pub struct MockHardware {
    pub cpu: f64,
    pub ram: f64,
    pub net: f64,
    pub temps: Vec<(String, f32)>,
}

#[cfg(test)]
impl HardwareProvider for MockHardware {
    fn refresh(&mut self) {}
    fn collect_data(&self, last_net_total: u64) -> (HardwareData, u64) {
        (HardwareData {
            cpu_usage: self.cpu,
            ram_used_gb: self.ram,
            total_ram_gb: 32.0,
            net_rx_mb: self.net,
            temps: self.temps.clone(),
        }, last_net_total + 100)
    }
}
