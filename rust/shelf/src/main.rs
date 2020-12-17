extern crate elf;

use std::fs;
use std::fs::Metadata;
use std::path::PathBuf;

const USAGE_STR: &str = "usage: shelf PATH";

fn main() {
    let mut args = std::env::args().skip(1);
    let path = args.next().expect(USAGE_STR);
    let path = PathBuf::from("tests/gdb/gdb");
    let file = match elf::File::open_path(&path) {
        Ok(f) => f,
        Err(e) => panic!("Error: {:?}", e),
    };

    let section = match file.get_section(".interp") {
        Some(s) => s,
        None => panic!("Failed to look up .interp section"),
    };

    // TODO: strip trailing null character from string: more elegantly?
    if section.data.len() > 1 {
        let as_str = String::from_utf8_lossy(&section.data[0..section.data.len() - 1]);
        println!("interpreter: {:?}", &as_str);

        // TODO: check if file path is valid
        // let metadata = fs::metadata(String::from(as_str)).unwrap();
        if let Ok(metadata) = fs::metadata(String::from(as_str)) {
            println!("permissions: {:?}", metadata.permissions())
        } else {
            // TODO: print nicer
            println!("invalid")
        }
    }
}
