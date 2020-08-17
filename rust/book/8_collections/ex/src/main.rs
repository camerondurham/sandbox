use std::collections::HashMap;

#[derive(Debug)]
struct Stats {
    mean: i32,
    median: i32,
    mode: i32,
}

fn stats(list: &Vec<i32>) -> Stats {
    let mut sum = 0;
    let mut map = HashMap::new();
    let len = list.len() as i32;

    for num in list {
        sum += num;
        let count = map.entry(num).or_insert(0);
        *count += 1;
    }

    let mut sorted = list.to_vec();

    sorted.sort();

    let mean = (sum) / (list.len() as i32);
    let middle = len / 2;
    let median = *sorted.get(middle as usize).unwrap();

    let mut max = 0;

    for (key, val) in &map {
        if val > map.get(&list[max]).unwrap() {
            max = **key as usize;
        }
    }

    let mode = *list.get(max as usize).unwrap_or(&0);

    Stats { mean, median, mode }
}

fn main() {
    let v = vec![1, 2, 3, 4, 5, 6, 1, 2, 3, 3, 3, 3, 4];
    let s = stats(&v);
    println!("{:?}", s);
}
