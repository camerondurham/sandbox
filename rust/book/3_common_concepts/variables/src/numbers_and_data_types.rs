use std::io;

fn main() {
    let _logical: bool = true;

    let _a_float: f64 = 1.0;
    let _an_integer = 5i32;

    let _default_float = 3.0;
    let _default_integer = 7;

    let mut _inferred_type = 12;
    _inferred_type = 4294967296i64;

    // bitwise operation
    println!("0011 AND 0101 is {:04b}", 0b0011u32 & 0b0101);
    println!("0011 OR 0101 is {:04b}", 0b0011u32 | 0b0101);
    println!("0011 XOR 0101 is {:04b}", 0b0011u32 ^ 0b0101);
    println!("1 << 5 is {}", 1u32 << 5);
    println!("0x80 >> 2 is 0x{:x}", 0x80u32 >> 2);

    let tuple_of_tuples = ((1u8, 2u16, 2u32), (4u64, -1i8), -2i16);
    println!("tuple_of_tuples {:?}", tuple_of_tuples);

    let pair = (1, true);
    println!("{:?}", pair);
    println!("Reversed: {:?}", reverse(pair));

    let tuple = (1, "hello", 4.5, true);

    println!("tuple: {:?}", tuple);

    let (a, b, c, d) = tuple;

    println!("{:?}, {:?}, {:?}, {:?}", a, b, c, d);
}

fn reverse(pair: (i32, bool)) -> (bool, i32) {
    let (integer, boolean) = pair;
    (boolean, integer)
}
