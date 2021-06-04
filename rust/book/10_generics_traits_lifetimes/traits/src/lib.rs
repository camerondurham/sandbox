use std::fmt::Display;
// Traits are similar to interfaces in other languages
pub trait Summary {
    fn summarize_author(&self) -> String;
    fn summarize(&self) -> String{
        format!("(Read more from {}...)", self.summarize_author())
    }
}

pub fn notify(item: &(impl Summary + Display)) {
    println!("Breaking news! {}", item.summarize());
}

// trait bound syntax
pub fn notifications<T: Summary + Display>(item1: &T, item2: &T) {
    println!("Breaking news! {}", item.summarize());
}

fn some_function<T, U>(t: &T, u: &U) -> i32
    where T: Display + Clone,
            U: Clone + std::Debug
{
    0
}

fn returns_summarizable() -> impl Summary {
    Tweet {
        username: String::from("horse_ebooks"),
        content: String::from(
            "of course, as you probably already know, people",
        ),
        reply: false,
        retweet: false,
    }
}

pub struct NewsArticle {
    pub headline: String,
    pub location: String,
    pub author: String,
    pub content: String,
}

impl Summary for NewsArticle {
    fn summarize_author(&self) -> String {
        format!("Author: {}", self.author)
    }
    fn summarize(&self) -> String {
        format!("{}, by {} ({})", self.headline, self.author, self.location)
    }
}

pub struct Tweet {
    pub username: String,
    pub content: String,
    pub reply: bool,
    pub retweet: bool,
}

impl Summary for Tweet {
    fn summarize_author(&self) -> String {
        format!("@{}", self.username)
    }
    // fn summarize(&self) -> String {
    //     format!("{}: {}", self.username, self.content)
    // }
}

pub fn test_tweet_summarize() {

    let tweet = Tweet  {
        username: String::from("horse_ebooks"),
        content: String::from(
            "of course, as you probably already know, people",
        ),
        reply: false,
        retweet: false,
    };

    println!("1 new tweet: {}", tweet.summarize());
    notify(&tweet);
}

pub fn test_news_article() {
    let article = NewsArticle {
        headline: String::from("Penguins win the Stanley Cup Championship!"),
        location: String::from("Pittsburgh, PA, USA"),
        author: String::from("Iceburgh"),
        content: String::from(
            "The Pittsburgh Penguins once again are the best \
            hockey team in the NHL.",
        ),
    };
    println!("New article available! {}", article.summarize());
    notify(&article);
}