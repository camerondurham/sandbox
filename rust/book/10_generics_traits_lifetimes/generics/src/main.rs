fn largest<T>(list: &[T]) -> T {
    let mut largest = list[0];
    for &item in list {
        if item > largest {
            largest = item;
        }
    }
    largest
}

struct Point<T> {
    x: T,
    y: T,
}

impl<T> Point<T> {
    fn x(&self) -> &T {
        &self.x
    }
}

// template specialization
impl Point<f32> {
    fn distance_from_origin(&self) -> f32 {
        (self.x.powi(2) + self.y.powi(2)).sqrt()
    }
}

struct PointTypes<T, U> {
    x: T,
    y: U,
}

impl<T, U> PointTypes<T, U> {
    fn mixup<V, W>(self, other: PointTypes<V, W>) -> PointTypes<T, W> {
        PointTypes {
            x: self.x,
            y: other.y,
        }
    }
}
fn main() {
    let number_list = vec![34, 50, 25, 100, 65];

    let result = largest (&number_list);
    println!("The largest number is {}", result);

    let char_list = vec!['y','m','a','q'];
    let result = largest (&char_list);
    println!("The largest char is {}", result);

    let both_integer = Point { x: 5, y: 10 };
    let both_float = Point { x: 5.0, y: 10.0 };

    // specify two types to use in Point
    // struct Point<T, U> {
    //     x: T,
    //     y: U,
    // }
    // let integer_and_float = Point { x: 6, y: 4.0 };

    let p1 = PointTypes{ x: 5, y: 10.4 };
    let p2 = PointTypes{ x: "Hello", y: 'c'};

    let p3 = p1.mixup(p2);

    println!("p3.x = {}, p3.y = {}", p3.x, p3.y);
}
