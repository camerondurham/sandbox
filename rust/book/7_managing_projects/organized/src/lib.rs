mod organized;

pub use crate::organized::another_library;
pub use crate::organized::inner_library;

fn utility() {}


pub struct Data {
    pub message: String,
    id: String,
}

pub mod in_file_library {
    pub fn helper() {
        private();
        crate::utility();
    }
    fn private() {}
}

fn some_function() {
    // relative path
    inner_library::helper();

    // absolute path
    crate::organized::another_library::helper();
    organized::another_library::helper();

    // access functions above the current `organized` module
    crate::utility();
}

pub fn message(msg: &str) -> Data {
    Data {
        message: String::from(msg),
        id: String::from("12345"),
    }
}


fn helper_function() {
    inner_library::helper();
    in_file_library::helper();
}

pub fn send_message(msg: &str) {
    let _msg = message(msg); 
}