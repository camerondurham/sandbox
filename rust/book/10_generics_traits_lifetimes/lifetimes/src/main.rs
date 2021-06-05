fn main() {
    println!("Hello, world!");
    {
        let r; // &i32
        {
            let x = 5; // i32
            r = &x;
        } // x dropped here while still borrowed

        // println!("r: {}", r)
        //                   - borrow later used here after being dropped
    }

    {
        let x = 5;            // ----------+-- 'b
                                  //           |
        let r = &x;         // --+-- 'a  |
                                  //   |       |
        println!("r: {}", r);     //   |       |
                                  // --+       |
    }                             // ----------+

    // Generic Lifetimes in Functions
    let string1 = String::from("abcd");
    let string2 = "xyz";

    let result = longest(string1.as_str(), string2);
    println!("The longest string is: {}", result);

    fn lifetimes<'a>(u: &'a i32, v: &'a mut i32) {
        // Lifetime Annotation Syntax
        let _w:i32 = 1;          // vanilla i32
        let _x:&i32 = &u;        // a reference
        let _y:&'a i32 = _x;      // a reference with an explicit lifetime
        let _z:&'a mut i32 = v;  // a mutable reference with an explicit lifetime
    }

    let u = 1;
    let mut v = 1;
    lifetimes(&u, &mut v);

    test_longest_nums();

    test_bigger_vec();

    test_struct();

    static_lifetime();
}

// this function requires an explicit lifetime to compile
fn longest<'a>(x: &'a str, y: &'a str) -> &'a str {
    // when we specify lifetimes in the function signature
    // we are not changing the lifetimes of any values passed
    // in or returned. instead, we're specifying that the
    // borrow checker should reject any values that don't
    // adhere to these constraints.
    if x.len() > y.len() {
        x
    } else {
        y
    }
}

fn longest_ignore_y<'a>(x: &'a str, y: &str) -> &'a str {
    x
}

// fn longest_unrelated_lifetime<'a>(x: &str, y: &str) -> &'a str {
//     let result = String::from("a really long stringy string");
//     // error[E0515]:
//     // returning a value referencing data owned by the current function
//     // result is borrowed here
//     result.as_ref()
// }

// lifetimes can be elided here since we don't need them
fn bigger(x: & i32, y: & i32) -> i32 {
    if x > y {
        x.clone()
    } else {
        y.clone()
    }
}

fn test_longest_nums() {
    // i thought bigger(x,y) would pass the borrow checker without
    // lifetime annotations on return type since i32's implement
    // the copy trait but **NO**! lifetime annotations seem to always
    // be necessary when returning a reference
    let x = 1;
    let y = 2;
    let z = bigger(&x, &y);
    println!("the larger number is: {}", z);
}

// this passes the borrow check, but why??
// i guess since it's explicit that i'm returning a reference
// to inside the vector v - let's see what the
// compiler enforces when calling this function
fn bigger_vec(v: Vec<&i32>) -> &i32 {
    let mut i = v[0];
    for item in v {
        if item > i {
            i = item;
        }
    }
    i
}

fn test_bigger_vec() {
    // i guess this is valid since &<literal> is valid since it
    // either is impl Copy/Clone or something?
    let v = vec![&1,&2,&3];
    let r = bigger_vec(v);
    println!("the largest element in v is: {}", r);
}


// Lifetime Annotations in Struct Definitions
struct ImportantExcerpt<'a> {
    part: &'a str,
}

fn test_struct() {
    let novel = String::from("Call me Ishmael. Some years ago...");
    let first_sentence = novel.split('.').next().expect("Could not find a '.'");
    let i = ImportantExcerpt {
        part: first_sentence,
    };
}

// Lifetime Elision
// this compiles without lifetime annotations
// since the compiler recognizes the pattern for
// this lifetime and doesn't need an explicit one
fn first_word(s: &str) -> &str {
    let bytes = s.as_bytes();

    for (i, &item) in bytes.iter().enumerate() {
        if item == b' ' {
            return &s[0..i];
        }
    }

    &s[..]
}

// Lifetime Annotations in Method Definitions
impl<'a> ImportantExcerpt<'a> {
    // first elision rule: all input parameters can be given a lifetime
    fn level(&self) -> i32 {
        3
    }

    // third elision rule: if there are multiple input lifetime params, but
    // one of them is &self or &mut self (since it's a method), the lifetime
    // of self is assigned to all output lifetime parameters
    fn announce_and_return_part(&self, announcement: &str) -> &str {
        println!("Attention please: {}", announcement);
        self.part
    }
}


fn static_lifetime() {
    // the static lifetime lives for as long as the program is running
    // this is because the static string is literally embedded into
    // the program's binary
    let s: &'static str = "I have a static lifetime.";
    println!("s = {}", s);
}

// All together now!
// Generic Type Parameters, Trait Bounds, and Lifetimes Together

use std::fmt::Display;

fn longest_with_an_announcement<'a, T> (
    x: &'a str,
    y: &'a str,
    ann: T,
) -> &'a str
where
T: Display,
{
    println!("Announcement! {}", ann);
    if x.len() > y.len() {
        x
    } else {
        y
    }
}