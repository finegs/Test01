#![allow(unused)]

use rand::Rng;
use core::num;
use std::fmt::Display;
use std::io;
use std::io::{Write, BufReader, BufRead, ErrorKind};
use std::fs::File;
use std::cmp::{Ordering, max_by_key};
use std::collections::HashMap;

mod restraurant;
use crate::restraurant::order_food;

fn main() {
    let path = "lines.txt";
    let output = File::create(path);
    let mut output = match output {
        Ok(file) => file,
        Err(error) => panic!("Problem creating file : {:?}", error)
    };

    write!(output, "Just some\nRandom words").expect("Failed to write file");

    let input = File::open(path).unwrap();
    let buffered = BufReader::new(input);
    // for line in buffered.lines() {
    //     println!("{}", line.unwrap());
    // }

    let output_file_name = "rand.txt";

    let rs = File::create(output_file_name);
    match rs {
        Ok(mut output_file) => {
            // write to file
            for rlr in buffered.lines() {
                match rlr {
                    Ok(ll) =>  { writeln!(output_file, "{}", ll); },
                    Err(err) =>  panic!("fail to read : {:?}, err : {:?}", output_file_name, err)
                }
            }
        },
        Err(err) => {
            match err.kind() {
                ErrorKind::AlreadyExists => {
                    // Open Output File
                    // Write to output file
                    match File::options().append(true).open(output_file_name) { 
                        Ok(mut output_file) => {
                            for rlr in buffered.lines() {
                                match rlr {
                                    Ok(ll) =>  { writeln!(output_file, "{}", ll); },
                                    Err(err) =>  panic!("fail to read : {:?}, err : {:?}", output_file_name, err)
                                }
                            }
                        },
                        Err(err) => {
                            panic!("Fail to open already exist : {:?}", output_file_name);
                        }
                    }
                },
                _err_kind => {
                    panic!("Fail to create output file : {:?}", output_file_name);
                }
            };
        }
    };



}

// use std::ops::Add;
// fn main() {
//     const ONE_MIL : u32 = 1_000_000;
//     const PI: f32 = 3.141592;
//     let age = "47";
//     let mut age: u32 = age.trim().parse()
//     .expect("Age was't assigned a number");
//     age = age+1;
//     println!("I'm {} and I want ${}", age, ONE_MIL);
// }

/*

use std::{env, fmt, fmt::Display, process};

struct Config { 
    query: String,
    file_path : String, ignore_case: bool
}

use std::collections::HashMap;
use std::collections::BTreeMap;

#[derive(Clone, Debug)] // we'll be cloning it later on
struct Node<'a> {
    data: &'a i32 
}

impl<'a> Node<'a> {
    fn set_data(&mut self, _data: &'a i32) {
        self.data = _data;
    }
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

pub fn my_add(a:i32, b:i32) -> i32 {
    return a+b;
}

pub fn my_bad_add(a:i32, b:i32) -> i32 { return a-b; }


#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_my_add() {
        assert_eq!(my_add(1,2), 3);
    }

    #[test]
    fn test_my_bad_add() {
        assert_ne!(my_bad_add(1,2), 3);
    }
}

fn main() {
    let stuff = Node {data: &12};
    let mut test = Test::new();

    test.join(stuff.clone());  // if we don't clone, `stuff` will get moved

    println!("{}", *test.hash_map["test"].data);  // outputs "12"
                                                  //
    let mut tmap: BTreeMap<String, Node> = BTreeMap::new();
    tmap.insert("bb".to_string(), Node{data : &200});
    tmap.insert("aa".to_string(), Node{data : &100});
    tmap.insert("2".to_string(), Node{data : &2});
    tmap.insert("1".to_string(), Node{data : &1});
    tmap.insert("0".to_string(), Node{data : &0});

    let nv = tmap["0"].data + 2;
    // tmap["0"].set_data(&(tmap["0"].data + 2));
    if let Some(x) = tmap.get_mut("0") {
        // let t = *x.data +2;
        // x.data = &t;
        x.set_data(&nv);
    }
    println!("tmap[{}]={}", "0", 100 + tmap["0"].data);
    println!("btreemap len : {}, data : {:?}", tmap.len(), tmap);
}

*/

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
    
    let mut args = env::args().skip(1).peekable();
    let mut input  : Result<&str, &str> = Err("No input file"); 
    let mut output : Result<&str, &str> = Err("No output file");
    match args.peek().map(|x| x.as_ref()) {
        None => {
            eprintln!("Error args");
            panic!("Error args");
        }
        Some("--in") => {
            input = match args.next() {
                Some(arg) => {
                    Ok(arg.clone().as_str())
                },
                None => {
                    eprintln!("No input file");
                    std::process::exit(1);
                }
             };
            // input = Ok(args.next().unwrap().as_str())
        }
        Some("--out") => {
            output = Ok(args.next().unwrap().as_str())
        }
        _ => {
            println!("Unsupported Options");
        }
    }

    match input {
        Ok(input_file) => {
            println!("Input file : {input_file}");
        }
        Err(err_msg) => {
            eprintln!("{}", err_msg);
        }
    }

    match output {
        Ok(output_file) => {
            println!("Output file : {}", output_file);
        }
        Err(err_msg) => {
            eprintln!("{}", err_msg);
        }
    match Config::build(args.clone().into_iter()) {
        Ok(cnf) => println!("### query:{}, file_path:{}, ignore_case:{}", 
                            cnf.query, cnf.file_path, cnf.ignore_case),
        Err(_) => eprintln!("Error : "),
    }

    // let mut args: Vec<String> = env::args().collect();


    // match Config::build(args.clone().into_iter()) {
    //     Ok(cnf) => println!("### query:{}, file_path:{}, ignore_case:{}", cnf.query, cnf.file_path, cnf.ignore_case),
    //     Err(_) => eprintln!("Error : "),
    // }

    // args = args.into_iter().map(|arg| arg.to_ascii_lowercase()).collect();
    // args.iter().for_each(|s| println!("{s}"));
}

*/

