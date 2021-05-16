fn main() {
    print_number(42);

    let expression_block = {
        let x = 3;
        x + 1
    };
    println!("expression_block: {}", expression_block);

    let x = five();
    println!("x = five(): {}", x);
    x += 1;
    println!("x: {}", x);
}

fn print_number(x: i32) {
    println!("The number is: {}", x);
}

fn five() -> i32 {
    5
}

fn test() -> u8 {
    100
}
