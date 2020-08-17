enum Message {
    Quit,                    // no contents
    Move { x: i32, y: i32 }, // has anonymous struct
    Write(String),
    ChangeColor(i32, i32, i32),
}

impl Message {
    fn call(&self) {
        // define method body
    }
}

fn main() {
    let m = Message::Write(String::from("hello"));
    m.call()
}
