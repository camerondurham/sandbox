use std::collections::HashMap;

pub fn num_identical_pairs(nums: Vec<i32>) -> i32 {
    let mut num_pairs = 0;
    let mut map: HashMap<i32, i32> = HashMap::new();
    for i in nums {
        if map.contains_key(&i) {
            map.insert(i, map[&i] + 1);
        } else {
            map.insert(i, 1);
        }
    }

    for val in map.values() {
        num_pairs += (val * (val - 1)) / 2
    }
    num_pairs
}

pub fn new_num_identical_pairs(nums: Vec<i32>) -> i32 {
    let mut accumulator = 0;
    let mut reference = nums[0];

    for x in 1..nums.len() {
        accumulator += nums.iter().skip(x).fold(0, |accum, &element| {
            accum + if element == reference { 1 } else { 0 }
        });
        reference = nums[x];
    }

    accumulator
}

fn main() {
    println!("{}", num_identical_pairs(vec![1, 2, 3, 1, 1, 3]));
    println!("{}", num_identical_pairs(vec![1, 1, 1, 1]));
    println!("{}", num_identical_pairs(vec![1, 2, 3]));
}
