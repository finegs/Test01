<!-- markdownlint-diable MD013 -->
# Project Overview: hw_monitor

`hw_monitor` is a Rust-based hardware monitoring application designed primarily for Windows systems. It provides a graphical user interface (GUI) to track system performance metrics such as CPU utilization, RAM usage, and APU temperature.

The project utilizes the following key technologies:

- **eframe/egui**: For building the immediate-mode GUI.
- **egui_plot**: For rendering real-time performance graphs.
- **sysinfo**: For cross-platform system information retrieval (CPU usage, Memory).
- **wmi**: For querying Windows Management Instrumentation, specifically targeting `LibreHardwareMonitor` for advanced sensor data.
- **serde**: For deserializing WMI query results.

## Persona/Goal

Act as a senior Rust engineer, DevOps engineer and UX engineer

## Coding Standards

Use functional programming, ECS architecture and keep SOLID principles.

## Architecture

The application is structured around a central `eframe` event loop.

- **`src/main.rs`**: This is the primary entry point. It implements a multi-threaded approach:
  - **Main Thread**: Handles the GUI rendering and standard metric collection (CPU/RAM) via `sysinfo`.
  - **Background Thread**: Periodically polls the `ROOT\LibreHardwareMonitor` WMI namespace to fetch detailed temperature and power data without blocking the GUI.
- **`src/__main.rs`**: An alternative, simpler implementation that uses `sysinfo::Components` for temperature monitoring. This version typically requires Administrator privileges on Windows to access hardware sensors directly.

## Building and Running

Ensure you have a Rust toolchain installed (2024 edition is required).

### Standard Run

```bash
cargo run
```

### Full Functionality (APU Telemetry)

The main version (`src/main.rs`) relies on **LibreHardwareMonitor** running in the background with "WMI Server" enabled.

1. Download and run [LibreHardwareMonitor](https://github.com/LibreHardwareMonitor/LibreHardwareMonitor).
2. Ensure it is running as Administrator.
3. Run the application: `cargo run`.

### Running the Alternative Version

To run the simpler `sysinfo`-based version, you would need to swap it into `src/main.rs` or use a cargo bin configuration (not currently configured in `Cargo.toml`).

## Development Conventions

- **Platform Specifics**: This application is heavily oriented towards Windows due to its reliance on WMI.
- **Threading**: Use background threads for blocking operations (like WMI queries) to maintain a responsive UI.
- **UI Repainting**: The UI requests a repaint every 500ms (or 1s in the alternative version) to balance real-time updates with CPU efficiency.
- **Error Handling**: WMI and COM initialization errors are handled gracefully, often resulting in a placeholder or warning message in the UI rather than a crash.
