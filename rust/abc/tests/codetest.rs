use chrono::Local;

use abc::tlog;
use abc::tlog::{telog, tlog};

#[test]
fn t01() {
    // let date_time: DateTime<Utc> = Utc.with_ymd_and_hms(2017, 04, 02, 12, 50, 32).unwrap();
    // let formatted = format!("{}", date_time.format("%d/%m/%Y %H:%M"));
    // assert_eq!(formatted, "02/04/2017 12:50");
    let ts: String = format!("{}", Local::now().format("%Y-%m-%d %H:%M:%S%.3f"));
    assert_eq!("2025-05-24 22:36:10.001".len(), ts.len());
}

/// @desc test macro tlog!
#[test]
fn t02() {
    tlog!("{} {} {}", 1 + 1, 2 + 2, "tail mesg");
}
