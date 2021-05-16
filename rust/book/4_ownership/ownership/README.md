# Ownership

When a variable is stored on the heap, we have to keep track of
the owner so we know when that variable can be dropped.

The memory pointed to by a `String` must have only one owner.


```rust
let s1 = String::from("hello");
let s2 = s1; // s1 moved into s2, s2 is now the sole owner

// using s1 will cause a compiler error
println!("{} {}", s1, s2);
```

However, we can use a more expensive copy operation ( `.clone()` )
if we want to perform a deep copy.

```rust
let s1 = String::from("hello");
let s2 = s1.clone(); // s1 is deeply copied into s2

// no compiler errors
println!("{} {}", s1, s2);
```

Note that if we did this with integer/float variables, cloning and
assigning would do the same thing since these variables' size is
known at compile time and are allocated on the stack.

This stack-only data types implement the `Copy` trait:

* All the integer types, such as `u32`.
* The Boolean type, `bool`, with values `true` and `false`.
* All the floating point types, such as `f64`.
* The character type, `char`.
* Tuples, if they only contain types that also implement `Copy`. For example, (`i32`, `i32`) implements `Copy`, but (`i32`, `String`) does not.