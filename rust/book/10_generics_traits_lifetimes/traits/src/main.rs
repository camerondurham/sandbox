mod lib;

use lib::{Tweet, NewsArticle};
use traits::{Summary, test_tweet_summarize, test_news_article};

fn main() {
    test_tweet_summarize();
    test_news_article();

}

fn largest<T: PartialOrd + Copy>(list: &[T]) -> T {
    let mut largest = list[0];
    for &item in list {
        if item > largest {
            largest = item;
        }
    }
    largest
}

// Use Trait bounds to Conditionally Implement Methods
// this implementation will only be valid for Pairs that implement Display + PartialOrd
use std::fmt::Display;

struct Pair<T> {
    x: T,
    y: T,
}

impl<T> Pair<T> {
    fn new(x: T, y: T) -> Self {
        Self {x, y}
    }
}

impl<T: Display + PartialOrd> Pair<T> {
    fn cmp_display(&self) {
        if self.x >= self.y {
            println!("The largest member is x = {}", self.x)
        } else {
            println!("The largest member is y = {}", self.y)
        }
    }
}


// Conditional implementation
// for anything that implements display to implement ToString
fn test_conditional_implementation() {
    // enabled by:
    // impl<T: Display> ToString for T {
    // // --snip--
    // }
    let _s = 3.to_string();
}