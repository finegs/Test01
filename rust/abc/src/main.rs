use std::cell::{RefCell, RefMut};
use std::collections::HashMap;
use std::rc::Rc;

pub fn main() {
    let shared_map = Rc::new(RefCell::new(HashMap::new()));

    {
        let mut map:  RefMut<'_, _> = shared_map.borrow_mut();

        map.insert("a", 1111);
        map.insert("b", 1010);
        map.insert("c", 202020);
    }

    let total = shared_map.borrow().values().sum::<i64>();
    println!("total : {}", &total);
}

