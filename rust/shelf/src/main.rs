extern crate elf;

use std::path::PathBuf;
use std::fs::Metadata;
use std::fs;

fn main() {
    let path = PathBuf::from("tests/gdb/gdb");
    let file = match elf::File::open_path(&path) {
        Ok(f) => f,
        Err(e) => panic!("Error: {:?}", e),
    };

    let section = match file.get_section(".interp") {
        Some(s) => s,
        None => panic!("Failed to look up .interp section"),
    };

    println!("{:?}", section.data);

    // TODO: strip trailing null character from string: more elegantly?
    if section.data.len() > 1 {
        let as_str = String::from_utf8_lossy(&section.data[0..section.data.len() - 1]);
        println!("as_str: {:?}", &as_str);

        // TODO: check if file path is valid
        let metadata = fs::metadata(String::from(as_str)).unwrap();
        println!("permissions: {:?}", metadata.permissions())
    }
}
