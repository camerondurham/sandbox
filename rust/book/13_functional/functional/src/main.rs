fn main() {
    let simulated_user_specified_value = 25;
    let simulated_random_number = 3;

    functional::generate_workout(simulated_user_specified_value, simulated_random_number);

    let x = 4;

    let equal_to_x = |z| z == x;

    // this won't compile
    //   = help: use the `|| { ... }` closure form instead
    // fn equal_to_x_func(z: i32) -> bool {
    //     z == x
    // }

    let y = 4;
    assert!(equal_to_x(y));
    assert!(equal_to_x_func(y));

    // Types of Fn traits:
    //
    // * `FnOnce`: consumes the variables it captures from enclosing scope - known as the closure's *environment*
    // * `FnMut` can change the environment because it mutably borrows values
    // * `Fn` borrows values from the environment immutably


    // Processing a series of items with iterators

    let v1 = vec![1,2,3];

    // Rust iterators are *lazy*: they have no effect until you call methods that consume the iterator to use it up
    let v1_iter = v1.iter();

    // only this part will do something
    for val in v1_iter {
        println!("Got: {}", val);
    }

    // all iterators implement a trait named Iterator defined in the standard library
    // pub trait Iterator { type item; fn next(&mut self) -> Option<Self::Item>; }
}
