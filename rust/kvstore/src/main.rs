fn main() {
    // https://youtu.be/WnWGO-tLtLA?t=2040
    let mut arguments = std::env::args().skip(1);
    let key = arguments.next().unwrap();
    let value = arguments.next().unwrap();
    println!("The key is '{}' and the value is '{}'", key, value);

}
