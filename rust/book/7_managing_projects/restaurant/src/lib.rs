// tels Rust to load contents of module
// from another file with the same name
mod front_of_house;

pub use crate::front_of_house::hosting;

fn serve_order() {}

mod back_of_house {
    fn fix_incorrect_order() {
        cook_order();
        super::serve_order();
    }
    fn cook_order() {}

    pub struct Breakfast {
        pub toast: String,
        seasonal_fruit: String,
    }

    impl Breakfast {
        pub fn summer(toast: &str) -> Breakfast {
            Breakfast {
                toast: String::from(toast),
                seasonal_fruit: String::from("peaches"),
            }
        }
    }

    pub enum Appetizer {
        Soup,
        Salad,
    }
}

use crate::front_of_house::hosting::add_to_waitlist;

pub fn dine_at_restaurant() {
    // Absolute path
    crate::front_of_house::hosting::add_to_waitlist();

    // using 'used' path
    add_to_waitlist();
    add_to_waitlist();
    add_to_waitlist();

    // Relative path
    front_of_house::hosting::add_to_waitlist();
}

pub fn eat_at_restaurant() {
    // Order a breakfast in the summer with Rye toast
    let mut meal = back_of_house::Breakfast::summer("Rye");

    // Change our mind about what bread we want
    meal.toast = String::from("Wheat");
    println!("I'd like {} toast please", meal.toast);

    // Cannot change the meal.seasonal_fruit field

    // will not compile: must annotate ALL fields pub
    // let order1 = back_of_house::Appetizer::Soup;
    // let order2 = back_of_house::Appetizer::Salad;
}
