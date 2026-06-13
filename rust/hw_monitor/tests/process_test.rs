use std::process::{Command, Stdio};
use std::io::{BufRead, BufReader};
use std::time::Duration;

#[test]
fn test_headless_execution() {
    // Build the binary first to ensure it's up to date
    let status = Command::new("cargo")
        .arg("build")
        .status()
        .expect("Failed to build binary");
    assert!(status.success());

    // Run the binary in headless mode directly (avoid cargo run for better control)
    let mut child = Command::new("target/debug/hw_monitor")
        .arg("--headless")
        .stdout(Stdio::piped())
        .stderr(Stdio::piped())
        .spawn()
        .expect("Failed to start process");

    let stdout = child.stdout.take().expect("Failed to open stdout");
    let reader = BufReader::new(stdout);
    
    let mut found_start = false;
    let mut found_end = false;

    // Read output in real-time or with a timeout
    for line in reader.lines() {
        let line = line.unwrap();
        println!("OUT: {}", line);
        if line.contains("Running in headless mode...") {
            found_start = true;
        }
        if line.contains("Headless execution successful.") {
            found_end = true;
            break;
        }
    }

    let status = child.wait_with_output().expect("Failed to wait for process");
    
    assert!(status.status.success());
    assert!(found_start, "Did not find start message");
    assert!(found_end, "Did not find success message");
}
