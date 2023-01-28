
use std::collections::HashMap;

#[derive(Clone)] // we'll be cloning it later on
struct Node<'a> {
    data: &'a i32 
}


struct Test<'a> {
    hash_map: HashMap<&'a str, Node<'a>>  // the hash map owns the struct
}

impl<'a> Test<'a> {
    fn new() -> Test<'a> {
        Test {hash_map: HashMap::new()}
    }

    fn join(
        &mut self, // must be mutable
        node: Node<'a>) { // do not pass a reference
        self.hash_map.insert("test", node);  // inserting moves `node`
    }
}

fn main() {
    let stuff = Node {data: &12};
    let mut test = Test::new();

    test.join(stuff.clone());  // if we don't clone, `stuff` will get moved

    println!("{}", *test.hash_map["test"].data);  // outputs "12"
}

/*
use std::collections::HashMap;

// pub type OptionMap = HashMap<String, Option<String>>;
pub type OptionMap = HashMap<String, Option<String>>;

fn test_option_map<'a>(map : &'a OptionMap, key : &'a String) {
    match map.get(key) {
        Some(ref v) => {
            match &v {
                 &&&Some(ref sval) => println!("Value found : key = {}, value = {}", key, sval),
                 &&&None => eprintln!("No value for key : {}", key)
            }
        },
        None => {
            eprintln!("Value not found. key={}", key);
        }
    }
}
fn main() {
    let mut ex  = OptionMap::new();

    let key = "test".to_string();
    ex.insert(key.clone(), None);

    test_option_map(&ex, &key);

    ex.insert(key.clone(), Some("Good".to_string()));

    test_option_map(&ex, &key);
}

*/

/*
use std::{env, fmt, fmt::Display};
struct Config {
    query: String,
    file_path : String,
    ignore_case: bool,
}

impl Display for Config {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> fmt::Result {
       f.write_fmt(format_args!("query:{}, file_path:{}, ignore_case:{}"
               , self.query
               , self.file_path
               , self.ignore_case))
    }
}

impl Config {
     pub fn build(
         args: impl Iterator<Item = String>,
     ) -> Result<Config, &'static str> {
        let mut args_iter = args.skip(1);
        let query = match args_iter.next() {
             Some(arg) => arg,
             None => return Err("Didn't get a query string"),
         };

         let file_path = match args_iter.next() {
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
        Ok(cnf) => println!("### query:{}, file_path:{}, ignore_case:{}", 
                            cnf.query, cnf.file_path, cnf.ignore_case),
        Err(_) => eprintln!("Error : "),
    }

    args = args.into_iter().map(|arg| arg.to_ascii_lowercase()).collect();
    args.iter().for_each(|s| println!("{s}"));
}

*/

