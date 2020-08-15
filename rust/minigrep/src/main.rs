use std::env;
use std::process;

use minigrep::Config;

// desired use:
// `cargo run searchstring example-filename.txt`

// run case insensitive search once like:
// `CASE_INSENSITIVE=1 cargo run to poem.txt`
fn main() {
    let args: Vec<String> = env::args().collect();

    // Config::new() returns a Result<T,E>
    // unwrap_or_else returns the value of Ok (T always?)
    // if value is Err value, method calls the *closure*
    // the *closure* is an anon function where params are
    // denoted inside the bars: |err|
    let config = Config::new(&args).unwrap_or_else(|err| {
        // when this block is reached, it will print out:
        //  Problem parsing arguments: not enough arguments
        // eprintln writes to std::err
        eprintln!("Problem parsing arguments: {}", err);
        process::exit(1);
    });

    if let Err(e) = minigrep::run(config) {
        eprintln!("Application error: {}", e);

        process::exit(1);
    }
}
