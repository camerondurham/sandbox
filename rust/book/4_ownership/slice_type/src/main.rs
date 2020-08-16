fn first_word_bad(s: &String) -> usize {
    let bytes = s.as_bytes();

    // enumerate wraps the result of iter in and each element as part of a tuple

    for (i, &item) in bytes.iter().enumerate() {
        if item == b' ' {
            return i;
        }
    }

    s.len()
}

fn first_word(s: &str) -> &str {
    let bytes = s.as_bytes();

    for (i, &item) in bytes.iter().enumerate() {
        if item == b' ' {
            return &s[0..i];
        }
    }

    &s[..]
}

fn main() {
    let s = String::from("hello world");

    // this code is brittle and buggy
    let _word = first_word_bad(&s); // will get the value 5
                                    // s.clear(); // empties string, sets value to "", causes bugs later

    // String Slices

    let hello = &s[0..5]; // [starting_index..ending_index] ending index not included
    let hello = &s[..5]; // [starting_index..ending_index] ending index not included

    let world = &s[6..11];
    println!("{}", hello);
    println!("{}", world);

    let fw = first_word(&s[..]);
    println!("First word: {}", fw);
}
