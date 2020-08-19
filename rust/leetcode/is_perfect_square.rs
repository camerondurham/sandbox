use std::cmp::Ordering;

pub fn is_perfect_square(num: i32) -> bool {
    if num == 1 {
        return true;
    }

    let mut low = 0u64;
    let mut high = (num as u64) / 2 + 1u64;
    let mut mid = high;

    while low < high {
        mid = low + (high - low) / 2;
        if mid * mid > (num as u64) {
            high = mid;
        } else {
            low = mid + 1;
        }
    }
    (low - 1) * (low - 1) == (num as u64)
}

pub fn is_perfect_square_2(num: i32) -> bool {
    let num: i64 = num as i64;
    let mut lo = 1;
    let mut hi = (num / 2) as i64;

    while low <= hi {
        let mid = low + ((hi - lo) / 2) as i64;

        match (mid * mid).cmp(&num) {
            Ordering::Less => lo = mid + 1,
            Ordering::Greater => hi = mid - 1,
            Ordering::Equal => {
                return true;
            }
        }
    }

    false || num == 1
}

// https://leetcode.com/problems/valid-perfect-square/discuss/622122/Rust-Newton's-method.-Beats-100
pub fn is_perfect_square_newtons(num: i32) -> bool {
    let eps = 1e-6;
    let mut x = num as f64;
    loop {
        let new_x = (x + num as f64 / x) / 2.0;
        if (new_x - x).abs() <= eps {
            break;
        }
        x = new_x;
    }

    let x = x.round() as i32;
    x * x == num
}

pub fn test(num: i32) {
    println!("{} is_perfect_square({})", is_perfect_square(num));
}

fn main() {
    test(3);
    test(9);
    test(1);
    test(2147483647);
}
