use std::io;
/*
 *  little sieve program check if a number is prime!
 */
const SIEVE_MIN: usize = 1;
const SIEVE_MAX: usize = 1_000_000;
fn main() {
    let mut sieve = [true; SIEVE_MAX];

    for i in 2..1000 {
        if sieve[i] {
            let mut j = i * i;
            while j < SIEVE_MAX {
                sieve[j] = false;
                j += i;
            }
        }
    }
    println!("Welcome to the Prime Number Checker!");
    println!("------------------------------------");
    println!(
        "Please enter a number in the range [{}, {}]: ",
        SIEVE_MIN, SIEVE_MAX
    );

    loop {
        print!(
            "Please enter a number in the range [{}, {}]: ",
            SIEVE_MIN, SIEVE_MAX
        );
        let mut guess = String::new();
        io::stdin()
            .read_line(&mut guess)
            .expect("Could not read number!");

        let guess: u32 = match guess.trim().parse() {
            Ok(num) => num,
            Err(_) => {
                println!("Please enter an integer");
                continue;
            }
        };

        let check: Option<u32> = Some(guess);

        match check {
            Some(guess) => {
                if (guess < (SIEVE_MIN as u32)) | (guess >= (SIEVE_MAX as u32)) {
                    println!("Number not in range, please try again. ");
                    continue;
                }
            }
            None => println!("Impossible state reached!"),
        };

        if sieve[(guess as usize)] {
            println!("{} is prime", guess);
        } else {
            println!("{} is not prime", guess);
        }
    }
}
