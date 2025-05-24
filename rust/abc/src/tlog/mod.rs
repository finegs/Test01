use chrono::Local;
use std::thread;

pub fn tlog<T: std::fmt::Display>(msg: T) {
    println!("{}", tmsg(msg));
}

pub fn telog<T: std::fmt::Display>(msg: T) {
    eprintln!("{}", tmsg(msg));
}

fn tmsg<T: std::fmt::Display>(msg: T) -> String {
    let now = Local::now();
    let tid = thread::current();
    format!(
        "{} - {:?} : {}",
        now.format("%Y-%m-%d %H:%M:%S%.3f"),
        tid,
        msg
    )
}

mod prelude {

    #[macro_export]
    macro_rules! tlog {
        ($fmt:literal) => {
            tlog($fmt);
        };
        ($fmt:literal $(, $args:expr)*) => {
            // TODO : hwo to use tlog fun in tlog! macro
            tlog(format!($fmt $(, $args)*));

        };
    }

    #[macro_export]
    macro_rules! telog {
        ($fmt:literal) => {
            telog($fmt);
        };
        ($fmt:literal $(, $args:expr)*) => {
            telog(format!($fmt $(, $args)*));
        };
    }
}
