use std::collections::HashSet;

pub fn num_jewels_in_stones(j: String, s: String) -> i32 {
    let mut ltrs = HashSet::new();
    let mut count = 0;
    for c in j.chars() {
        ltrs.insert(c);
    }
    for c in s.chars() {
        if ltrs.contains(&c) {
            count = count + 1;
        }
    }
    count
}

fn main() {
    let j = "aA".to_string();
    let s = "aAAbbbb".to_string();
    assert_eq!(num_jewels_in_stones(j, s), 3);

    let j = "z".to_string();
    let s = "ZZ".to_string();
    assert_eq!(num_jewels_in_stones(j, s), 0);
}
