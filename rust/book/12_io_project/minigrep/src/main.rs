use std::{env, process};
use minigrep::Config;

/*

main handles:
    * calling command line parsing logic with arg values
    * setting up any configuration
    * calling a `run` function in lib.rs
    * handling the error if `run` returns an error

*/
fn main() {

    let args: Vec<String> = env::args().collect();

    // note using primtive values (&str, &str) when
    // a complex type is more appropriate is an
    // anti-pattern known as *primitive obsession*
    // let (query, filename) = parse_config(&args);

    let config = Config::new(&args).unwrap_or_else(|err| {
        eprintln!("Problem parsing arguments: {}", err);
        process::exit(1);
    });

    if let Err(e) = minigrep::run(config) {
        eprintln!("Application error: {}", e);
        process::exit(1);
    }
}
// fn parse_config(args: &[String]) -> Config {
//     // TODO: is this less efficient than using args[n].clone() ??
//     Config {
//         query: String::from(&args[1]),
//         filename: String::from(&args[2]),
//     }
// }