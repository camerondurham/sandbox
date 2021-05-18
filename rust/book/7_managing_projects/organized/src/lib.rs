fn utility() {}

mod organized {

    pub struct Data {
        pub message: String,
        id: String,
    }

    pub mod inner_library {
        pub fn helper() {
            private();
            // super acts like `..` in a directory structure
            super::super::utility();
        }
        fn private() {}
    }

    pub mod another_library {
        pub fn helper() {}
    }

    fn some_function() {
        // relative path
        inner_library::helper();

        // absolute path
        crate::organized::another_library::helper();

        // access functions above the current `organized` module
        super::utility();
    }

    pub fn msg(msg: &str) -> Data {
        Data {
            message: String::from(msg),
            id: String::from("12345"),
        }
    }

}

fn helper_function() {
    organized::inner_library::helper();
}

pub fn send_message(msg: &str) {
    let msg = organized::msg("hello, world!");
}