use std::collections::HashMap;
use std::collections::HashSet;
use std::fs::File;
use std::io::{BufRead, BufReader};
fn main() {
    //     let numbers: Vec<i64> = (1..1000).collect();
    //     println!("{:?}", numbers);

    let path = "/usr/share/dict/words";
    let input = File::open(path).unwrap();
    let buffered = BufReader::new(input);

    let words: Vec<String> = buffered.lines().filter_map(Result::ok).collect();

    let words_length: HashMap<_, usize> = words.iter().map(|word| (word, word.len())).collect();

    // let word_length: HashMap<usize, _> = words.iter().map(|word| (word.len(), word)).collect();

    let mut word_length: HashMap<usize, _> = HashMap::new();

    for word in words {
        word_length
            .entry(word.len())
            .or_insert(HashSet::new())
            .insert(word);
    }

    println!("{:?}", word_length[&3]);

    // for line in buffered.lines() {
    //     println!("{}", line.unwrap());
    // }
}
