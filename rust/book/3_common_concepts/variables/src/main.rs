#![allow(unused_variables)]

const _EXAMPLE_CONST_MAX_VAL: u32 = 100_000;

fn main() {
    // Variables and mutability
    let shadowed_var = 5;
    let shadowed_var = shadowed_var + 1;
    let shadowed_var = shadowed_var * 2;
    println!("The value of shadowed_var is: {}", shadowed_var);

    // Data Types

    //  Scalar Types
    let float_type = 2.0; // f64
    let smaller_float_type: f32 = 3.0; // f32
    println!("a f64: {}, a f32: {}", float_type, smaller_float_type);

    let heart_eyed_cat = '😻';
    println!("An emoji: {}", heart_eyed_cat);

    //  Compound Types
    let tup: (i32, f64, u8) = (500, 6.4, 10);

    let (x, y, z) = tup;

    println!("(x,y,z) = ({},{},{})", x, y, z);
    println!(
        "wtf this tuple syntax is wack... this is just the u8: {}",
        tup.2
    );

    let arr = [1, 2, 3, 4, 5];

    let explicit_typed_array: [i32; 3] = [1, 2, 3];
    let array_of_four_ones = [1; 4];

    let months = [
        "January",
        "February",
        "March",
        "April",
        "May",
        "June",
        "July",
        "August",
        "September",
        "October",
        "November",
        "December",
    ];

    // panics at runtime since Rust checks the index of the array before accessing it
    // for i in 0..20 {
    //     println!("{}", months[i]);
    // }
}
