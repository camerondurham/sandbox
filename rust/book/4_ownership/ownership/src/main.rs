fn main() {
    // Strings can be mutated
    // literals cannot
    let mut s = String::from("hello");

    s.push_str(", world!🦀");

    println!("{}", s);

    // moving heap data
    let original_str = String::from("hello");
    let moved_str = original_str;

    println!("old: [CANNOT BE BORROWED AFTER MOVE!] new: {}", moved_str);

    let s1 = String::from("hello");
    let s2 = s1.clone();

    println!("s1: {}, s2: {}", s1, s2);

    // stack only copy

    // bool, floating point, char, and tuples with these values
    // have `Copy` trait

    let x = 5;
    let y = x;
    println!("x: {}, y: {}", x, y);

    // transferring ownership
    let (s3, len) = calculate_length(s1);
    println!("s3: {}, len: {}", s3, len);

    // using references
    println!("len of string: {} is {}", s3, calc_len(&s3));

    let s3_ref = &s3;
    println!("s3: {}, moved_maybe: {}", s3, s3_ref);

    let moved_ref = s3_ref;
    println!("s3: {}, moved_ref: {}", s3, moved_ref);

    // cannot move out of `s3` because it is borrowed
    // let moved_actual = s3;

    // mutable references
    let mut s = String::from("crabby");
    change(&mut s);

    println!("changed str: {}", s);

    // no problem to have mutable refs
    // cannot be simultaneous though

    let mut s = String::from("hello");

    {
        let _r1 = &mut s;
    } // r1 goes out of scope here, so we can make a new reference with no problems.

    let _r2 = &mut s;

    // cannot use mutable and immutable references to a variable

    let _r1 = &s;
    let _r2 = &s;
    let _bad = &mut s; // big problem from here!!!

    // println!("{}{}{}", _r1, _r2, _bad);

    let r1 = &s;
    let r2 = &s;

    println!("these vars aren't used after this: {}, {}", r1, r2);

    // now a mutable reference can be used

    let mut_ref = &mut s;
    println!("mut_ref: {}", mut_ref);
}

fn calculate_length(s: String) -> (String, usize) {
    let length = s.len();

    (s, length)
}

fn calc_len(s: &String) -> usize {
    // & allows us to refer to a value
    // that we don't own
    s.len()
}

fn change(s: &mut String) {
    s.push_str("🦀");
}
