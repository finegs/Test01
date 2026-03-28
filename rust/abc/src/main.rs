use std::cell::{RefCell, RefMut};
use std::collections::HashMap;
use std::rc::Rc;

use crate::tlog::{telog, tlog};

mod tlog;

pub fn main() {
    let v_a = 1111;
    let v_b = 1010;
    let v_c = 202020;
    let shared_map = Rc::new(RefCell::new(HashMap::new()));
    {
        let mut map: RefMut<'_, _> = shared_map.borrow_mut();

        map.insert("a", v_a);
        map.insert("b", v_b);
        map.insert("c", v_c);
    }

    let total = shared_map.borrow().values().sum::<i64>();
    let total_org = v_a + v_b + v_c;

    tlog!("aaa {} + {} = {}", 1, 2, 1 + 2);
    tlog!("total : {}", total);

    assert_eq!(total, total_org, "assert_eq!({}, {})", total, total_org);

    if total == 0 {
        telog!("&{} == &{}", total, 0);
    }

    {
        use std::cell::RefCell;

        let c = RefCell::new("hello".to_owned());

        *c.borrow_mut() = "bonjour".to_owned();

        assert_eq!(&*c.borrow(), "bonjour");
    }

    {
        use std::cell::RefCell;

        let c = RefCell::new(5);
        // RefCell::borrow in a block is ok when other borrow_mut/borrow is not  in a same block(
        // parent or child block is ok)
        {
            let m = c.borrow();
        }

        let b = c.borrow_mut(); // this causes a panic
    }
}
