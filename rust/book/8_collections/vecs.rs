fn main() {
    let mut v = vec![1, 2, 3, 4, 5];

    // stores None
    let dne = v.get(100);

    // panics
    // let does_not_exist = &v[100];
    let does_not_exist = v.get(100);

    let first = &v[0];

    // may require allocating more memory and copying old elements
    // to new space
    v.push(6);

    // will not compile with this line
    // println!("The first element is: {}", first);

    let mut v = vec![100, 32, 57];

    for i in &mut v {
        *i += 50;
    }

    for i in &v {
        println!("{}", i);
    }

    let v = vec![1,2,3,4,5];

    let third:  &i32 = &v[2];
    println!("The third element is {}", third);

    match v.get(2) {
        Some(third) => println!("The third element is {}", third),
        None => println!("There is no third element."),
    }
}
