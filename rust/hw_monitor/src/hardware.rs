use sysinfo::{CpuRefreshKind, MemoryRefreshKind, RefreshKind, System, Disks, Networks, Components};

#[derive(Clone)]
pub struct DiskData {
    pub mount_point: String,
    pub used_gb: f64,
    pub total_gb: f64,
}

pub struct HardwareData {
    pub cpu_usage: f64,
    pub ram_used_gb: f64,
    pub total_ram_gb: f64,
    pub net_rx_mb: f64,
    pub net_tx_mb: f64,
    pub temps: Vec<(String, f32)>,
    pub disks: Vec<DiskData>,
}

pub trait HardwareProvider: Send + Sync {
    fn refresh(&mut self);
    fn collect_data(&self, last_net_rx: u64, last_net_tx: u64) -> (HardwareData, u64, u64);
}

pub struct RealHardware {
    sys: System,
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
        self.disks.refresh_list();
    }

    fn collect_data(&self, last_net_rx: u64, last_net_tx: u64) -> (HardwareData, u64, u64) {
        let cpu_usage = self.sys.global_cpu_info().cpu_usage() as f64;
        let ram_used_gb = self.sys.used_memory() as f64 / 1_073_741_824.0;
        let total_ram_gb = self.sys.total_memory() as f64 / 1_073_741_824.0;
        
        let mut net_rx = 0u64;
        let mut net_tx = 0u64;
        for (_, data) in &self.networks {
            net_rx += data.received();
            net_tx += data.transmitted();
        }
        let net_rx_mb = if last_net_rx > 0 {
            (net_rx.saturating_sub(last_net_rx)) as f64 / 1_048_576.0
        } else { 0.0 };
        let net_tx_mb = if last_net_tx > 0 {
            (net_tx.saturating_sub(last_net_tx)) as f64 / 1_048_576.0
        } else { 0.0 };

        let temps = self.components.iter().map(|c| (c.label().to_string(), c.temperature())).collect();

        let disks = self.disks.iter().map(|d| {
            let total = d.total_space() as f64 / 1_073_741_824.0;
            let available = d.available_space() as f64 / 1_073_741_824.0;
            DiskData {
                mount_point: d.mount_point().to_string_lossy().to_string(),
                used_gb: total - available,
                total_gb: total,
            }
        }).collect();

        (HardwareData {
            cpu_usage,
            ram_used_gb,
            total_ram_gb,
            net_rx_mb,
            net_tx_mb,
            temps,
            disks,
        }, net_rx, net_tx)
    }
}

#[cfg(test)]
pub struct MockHardware {
    pub cpu: f64,
    pub ram: f64,
    pub net_rx: f64,
    pub net_tx: f64,
    pub temps: Vec<(String, f32)>,
    pub disks: Vec<DiskData>,
}

#[cfg(test)]
impl HardwareProvider for MockHardware {
    fn refresh(&mut self) {}
    fn collect_data(&self, last_net_rx: u64, last_net_tx: u64) -> (HardwareData, u64, u64) {
        (HardwareData {
            cpu_usage: self.cpu,
            ram_used_gb: self.ram,
            total_ram_gb: 32.0,
            net_rx_mb: self.net_rx,
            net_tx_mb: self.net_tx,
            temps: self.temps.clone(),
            disks: self.disks.clone(),
        }, last_net_rx + 100, last_net_tx + 50)
    }
}
