const LOOPS: u8 = 5;

fn main() {
    let number = 5;
    if number < 4 {
        println!("condition was true");
    } else {
        println!("condition was false");
    }

    // using if in a let statement
    let condition = true;

    // let statements be expressions with { 4 }...
    let _number = if condition { 4 } else { 2 };

    println!("and i...");

    let mut x = 0;
    loop {
        println!("loop");
        if x == LOOPS {
            break;
        }
        x += 1;
    }
    println!("done");

    let mut number = 3;

    while number != 0 {
        println!("{}!", number);
        number -= 1;
    }

    let mut counter = 0;

    let result = loop {
        counter += 1;

        if counter == 10 {
            break counter * 2;
        }
    };
    println!("The result is {}", result);

    let mut number = 3;

    while number != 0 {
        println!("{}!", number);
        number -= 1;
    }

    println!("LIFTOFF!!!");

    let arr = [00, 01, 02, 03];

    for element in arr.iter() {
        println!("the value is: {}", element);
    }

    for number in (1..4).rev() {
        println!("{}!", number);
    }

    let val = 35.;
    println!("{}°C = {}°F", val, convert_to_fahrenheit(val));
    println!("{}°F = {}°C", val, convert_to_celsius(val));

    let n = 5;
    println!("{}th fibonacci: {}", n, fib(n));
}

fn convert_to_fahrenheit(c: f32) -> f32 {
    (c * 9. / 5.) + 32.
}

fn convert_to_celsius(f: f32) -> f32 {
    (f - 32.) * (5. / 9.)
}

fn fib(n: i32) -> i32 {
    if n <= 0 {
        0
    } else if n == 1 {
        1
    } else {
        fib(n - 1) + fib(n - 2)
    }
}
