# Enums

Rust's enums are most similar to *algebraic data types* in functional languages such as F#, OCaml, and Haskell.

## Algebraic data type

A type formed by combining other types (a *composite type*). Two common classes are
product types (i.e. tuples and records) and sum types (i.e. tagged or disjoint unions).

The values of product type typically contains several values, called *fields*.

The values of a sum type are typically grouped into several classes called *variants*.

Haskell example:

`data Pair = P Int Double` a Pair is an int and a double
`data Pair I Int | D Double` a Pair is an int or a double

Slightly more complicated example (a tree in haskell):

```hs
data Tree = Empty
          | Leaf Int
          | Node Tree Tree
```

References:

* https://wiki.haskell.org/Algebraic_data_type
* https://en.wikipedia.org/wiki/Algebraic_data_type


## Defining an Enum

```rust
enum IpAddrKind {
  V4,
  V6
}
```

Enums can be composed of other types as well:

```rust
enum IpAddr {
  V4(String),
  V6(String),
}

let home = IpAddr::V4(String::from("127.0.0.1"));
let loopback = IpAddr::V6(String::from("::1"));
```

An enum can be composed of different types for each variant:

```rust
enum IpAddr {
  V4(u8, u8, u8, u8),
  V6(String),
}

let home = IpAddr::V4(127,0,0,1);
let loopback = IpAddr::V6(String::from("::1"));
```

## Option

The option type as defined by the standard library:

```rust
enum Option<T> {
  Some(T),
  None,
}

let some_number = Some(5);
let some_string = Some("a string");
let absent_number: Option<i32> = None;
```

A huge advantage of using `Option<T>` is that Rust will not allow you to
represent a "`null`" state. Instead, you must use an `Option<T>` and
explicitly check for `None`.

For example, this won't compile since the types are different:

```rust
let x: i8 = 5;
let y: Option<i8> = Some(5);
let sum = x + y; // will not compile since there's no implementation
                 // for i8 + Option<i8>
```

Instead, you must explicitly convert the `Option<T>` to a `T`.

For docs on `Option<T>` see: https://doc.rust-lang.org/std/option/enum.Option.html