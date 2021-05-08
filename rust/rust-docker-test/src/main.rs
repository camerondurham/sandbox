use std::time::Instant;

fn main() {
    let n = 10_000;
    let now = Instant::now();
    let nth = nth_prime(n);
    let elapsed = now.elapsed().as_micros();
    println!("prime #{} = {}", n, nth);
    println!("elapsed = {} µs", elapsed);
}

fn nth_prime(n: u64) -> u64 {
    let mut count = 1;
    let mut num = 2;
    while count < n {
        num += 1;
        if is_prime(num) {
            count += 1;
        }
    }
    num
}

fn is_prime(num: u64) -> bool {
    for i in 2..num {
        if num % i == 0 {
            return false;
        }
    }
    true
}