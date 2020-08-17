fn main() {
    let x = Some("air");
    assert_eq!(x.unwrap(), "air");

    let x: Option<&str> = None;
    assert_eq!(x.unwrap(), "air");

    assert_eq!(Some("car").unwrap_or("bike"), "car");

    // recommended to use unwrap_or_else
    let k = 10;
    assert_eq!(Some(4).unwrap_or_else(|| 2 * k), 4);
}
