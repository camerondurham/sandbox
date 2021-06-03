use std::fs::{File, self};
use std::io::{ErrorKind, Read, self};
use std::error::Error;

fn crash_and_burn() {
    panic!("crash and burn")
}

fn read_username_from_file_verbose() -> Result<String, io::Error> {
    let f = File::open("hello.txt");

    let mut f = match f {
        Ok(file) => file,
        Err(e) => return Err(e),
    };

    let mut s = String::new();

    match f.read_to_string(&mut s) {
        Ok(_) => Ok(s),
        Err(e) => Err(e),
    }
}

fn read_username_from_file_concise() -> Result<String, io::Error> {
    // let mut f = File::open("hello.txt")?;
    // let mut s = String::new();
    // f.read_to_string(&mut s)?;
    // Ok(s)

    // chaining method calls
    let mut s = String::new();

    File::open("hello.txt")?.read_to_string(&mut s)?;

    Ok(s)
}

fn read_username_from_file() -> Result<String, io::Error> {
    fs::read_to_string("hello.txt")
}

// The main function is special and there are restrictions on its return type.
// One valid return type is (), another valid type is Result<T, T>:
// dyn Error basically means "any kind of error" and dyn is kind of like
// c++ virtual functions
fn main() -> Result<(), Box<dyn Error>> {
    println!("Hello, world!");
    let v = vec![1,2,3];
    // causes a panic/OOB error
    // v[99];
    // crash_and_burn();

    let f = File::open("hello.txt");

    let f = match f {
        Ok(file) => file,
        Err(error) => match error.kind() {
            ErrorKind::NotFound => match File::create("hello.txt") {
                Ok(fc) => fc,
                Err(e) => panic!("Problem creating the file: {:?}", e),
            },
            other_error => {
                panic!("Problem opening the file: {:?}", other_error)
            }
        },
    };

    // more sophisticated way to write this 🦀

    // the primary improvement is it doesn't include the `match` primitive
    // TODO: review this after chapter 13 about unwrap_or_else
    let f = File::open("hello.txt").unwrap_or_else(|error| {
        if error.kind() == ErrorKind::NotFound {
            File::create("hello.txt").unwrap_or_else(|error| {
                panic!("Problem creating the file: {:?}", error);
            })
        } else {
            panic!("Problem opening the file: {:?}", error);
        }
    });

    // use the Result<T, E> return type

    let f = File::open("hello.txt")?;

    Ok(())
}


// example: acceptable to call unwrap since you'll never have an `Err` variant
fn example1() {
    use std::net::IpAddr;
    let _: IpAddr = "127.0.0.1".parse().unwrap();
}