pub fn my_sqrt(x: i32) -> i32 {
    let mut low = 0u64;
    let mut high = (x as u64) + 1u64;
    let mut mid = low;

    while low < high {
        mid = low + (high - mid) / 2;
        if mid * mid > x as u64 {
            high = mid;
        } else {
            low = mid + 1;
        }
    }
    (low - 1u64) as i32
}

#[cfg(test)]
mod tests {

    use super::*;

    fn trivial() {
        assert_eq!(my_sqrt(9), 3);
    }

    fn overflow() {
        assert_eq!(my_sqrt(2147483647), 46340);
    }
}

fn main() {
    assert_eq!(my_sqrt(9), 3);
    assert_eq!(my_sqrt(2147483647), 46340);
}
