//! # Notes on Writing Documentation
//!
//! That's the purpose of these comments!
//! Run this to view this page in a browser:
//! ```
//! cargo doc --open
//! ```
//!
//! ## Commonly Used Sections
//!
//! Authors usually write documentation to describe when their crate will do the following
//! so the caller can avoid doing this:
//! - **Panics**: when function being documented could panic
//! - **Errors**: if the function returns a `Result` and when it would return an Err and what type of errors it might return
//! - **Safety**: if the function is unsafe to call, there should be a section explaining why the function is unsafe and covering invariants that the function expects the callers to uphold.
//!
//! ## Documentation Comments as Tests
//!
//! Add example code blocks in your documentation comments can help demonstrate how to use your library, and doing so has an additional bonus:
//! running `cargo test` will run the code examples too!

/// Adds one to the number given.
/// # Examples
/// ```
/// let arg = 5;
/// let answer = my_crate::add_one(arg);
///
/// assert_eq!(6, answer);
/// ```
pub fn add_one(x: i32) -> i32 {
    x + 1
}

pub use self::kinds::PrimaryColor;
pub use self::kinds::SecondaryColor;
pub use self::utils::mix;

pub mod kinds {
    /// The primary colors according to the RYB color model.
    pub enum PrimaryColor {
        Red,
        Yellow,
        Blue,
    }

    /// The secondary colors according to the RYB color model.
    pub enum SecondaryColor {
        Orange,
        Green,
        Purple,
    }
}

pub mod utils {
    use crate::kinds::*;

    /// Combines two primary colors in equal amounts to create a secondary color
    pub fn mix(c1: PrimaryColor, c2: PrimaryColor) -> SecondaryColor {
        // --snip--
        //ANCHOR_END: here
        SecondaryColor::Orange
        // ANCHOR: here
    }
}

#[cfg(test)]
mod tests {
    #[test]
    fn it_works() {
        assert_eq!(2 + 2, 4);
    }
}
