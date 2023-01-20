use std::{env, fmt, fmt::Display};
struct Config {
    query: String,
    file_path : String,
    ignore_case: bool
}

impl Display for Config {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> fmt::Result {
       f.write_fmt(format_args!("query:{}, file_path:{}, ignore_case:{}", self.query, self.file_path, self.ignore_case))
    }
}

impl Config {
     pub fn build(
         mut args: impl Iterator<Item = String>,
     ) -> Result<Config, &'static str> {
         args.next();

         let query = match args.next() {
             Some(arg) => arg,
             None => return Err("Didn't get a query string"),
         };

         let file_path = match args.next() {
             Some(arg) => arg,
             None => return Err("Didn't get a file path"),
         };

         let ignore_case = env::var("IGNORE_CASE").is_ok();

         Ok(Config {
             query,
             file_path,
             ignore_case,
         })
     }
}
fn main() {
    let mut args: Vec<String> = env::args().collect();

    match Config::build(args.clone().into_iter()) {
        Ok(cnf) => println!("### query:{}, file_path:{}, ignore_case:{}", cnf.query, cnf.file_path, cnf.ignore_case),
        Err(_) => eprintln!("Error : "),
    }

    args = args.into_iter().map(|arg| arg.to_ascii_lowercase()).collect();
    args.iter().for_each(|s| println!("{s}"));
}
