# Golang

## Tour of Go

Exported names
 - names that begin with a capital letter are exported from a package. ex: `math.Pi`

### Functions

```go
package main
import "fmt"

func add(x int, y int) int {
    return x + y
}

// shortened type annotations
func add(x, y int) int {
    return x + y
}

// multiple results
func nums(x int, y string) (string, int) {
	return y, x
}

func main() {
	fmt.Println(nums(2020, "biden"))
}
```

Named return values in Golang should only be used for short functions.
The `return` without arguments returned the named return values.

```go
func toMinutes(seconds int) (hours, secondsRemain int) {
	hours = seconds / 60
	secondsRemain = seconds % 60
	return
}
```

### Variables

The `var` statement declares one or more variables, the type is written last:

`var a, b, c int`

A `var` declarations can also initialize variables:

`var c, python, java = true, false, "no!"`

Short variable declarations, without specifying `var`.

`joe := "president-elect"`


`c, python, java := true, false, "no!"`


#### Zero Values

When variables are declared without an explicit value, they are given their *zero value*

Numeric types: `0`

Boolean types: `false`

Strings: `""`

#### Type Conversions

Type conversions in Go are done using `T(value)`, for example: `float64(someInt)`

You must explicitly give the type in Golang, types are not implicitly converted for numeric types.

**Problem:**
`var z uint = uint(f)`

**Error:**
`cannot use f (type float64) as type uint in assignment`


**Constants**

Constants are declared with the `const` keyword. They can be character, string, boolean, or numeric types.
Constants cannot use the `:=` syntax.
`const Pi = 3.14`


### Control Flow

```go
package main
import (
	"fmt"
	"runtime"
	"time"
)
func main() {
    sum := 0
    for i := 0; i < 10; i++ {
        sum += 10
    }
    fmt.Println(sum)

    // init and increment statements are optional
    // the for loop is Go's `while`
    num := 1
    for ; num < 1000 ; {
        num += 10
    }

    // a lovely infinite loop
    for {}

    // if statements
    // braces are required
    x := -9
    if x < 0  {
        fmt.Println(math.Sqrt(-x), "i")
    }

    // if with a short statement
    // if's can start with a short statement to execute before the condition

    if remainder := x % 13; remainder != 0 {
        fmt.Println("13 doesn't divide x evenly: ", remainder)
    } else {
        // remainder is out of scope here
        fmt.Println("13 is a divisor of x")
    }

    // switch statements
    fmt.Print("Go runs on ")
    switch os := runtime.GOOS; os {
	case "darwin":
		fmt.Println("OS X.")
	case "linux":
		fmt.Println("Linux.")
	default:
		// freebsd, openbsd
		// plan9, windows
		fmt.Printf("%s.\n", os)
    }

    // switch statements evaluate from top to bottom,
    // stopping when a case succeeds

    // a switch without a condition is the same as true
    t := time.Now()
    switch {
	case t.Hour() < 12:
		fmt.Println("Good morning!")
	case t.Hour() < 17
		fmt.Println("Good afternoon.")
	default:
		fmt.Println("Good evening.")
    }

}
```

**Defer:**
A defer statement defers execution of a function until the surrounding function returns.


```go
package main

import "fmt"

func main() {
	defer fmt.Println("world")
	fmt.Println("hello")
}
```

The defer statement pushes a function call onto a list. The list of saved calls is executed after the surrounding
function returns. It is commonly used to simplify functions that perform various clean-up actions.

*Example:*

```go
func CopyFile(dstName, srcName string) (written int64, err error) {
    src, err := os.Open(srcName)
    if err != nil {
        return
    }
    // defer statement ensures files are always closed
    // in case of an error when opening the file
    defer src.Close()

    dst, err := os.Create(dstName)
    if err != nil {
        return
    }
    defer dst.Close()

    return io.Copy(dst, src)
}
```

### Pointers

Pointers hold the address of a memory value. These behave the mostly the same way as in C/C++ but Go has no pointer arithmetic.

```go
i := 42
p = &i
fmt.Println(*p) // read value of p
*p = 21         // set i through the pointer p
```

### Struct

A `struct` is a collection of fields. The fields are accessed using a dot. A pointer to a struct can also be accessed with a dot.

```go
type Vertex struct {
	X int
	Y int
}
func main() {
	v := Vertex{1,2}
	p := &v
	p.X = 1e9
}
```

**Struct literals**

You can list only a subset of fields by using the `Name:` syntax (then order of the fields won't matter).

```go
type Vertex struct {
	X, Y int
}
var (
	v1 = Vertex{1,2}
	v2 = Vertex{X: 1}   // Y:0 is implicit
	v3 = Vertex{}       // both are zero
)
```

### Arrays

Arrays length is part of its type. Arrays cannot be resized.
```go
// a is an array ot 10 integers
var a [10]int
```

**Slices** are a dynamically-sized, flexible view into the elements of an array. A slices of type `T` has type `[]T`.

```go
// includes low, doesn't include high
a[low : high]
```

**Slices** are references to an array. Changing slice elements modifies the underlying array.

```go
names := [4]string{
	"joe",
	"kamala",
	"elizabeth",
	"bernie"
}

a := names[0:2]
b := names[1:3]

// changes names[2]
b[1] = "alex"
```

Slice defaults:

```go
var a [10]int

// equivalent expressions
a[0:10]
a[0:]
a[:10]
a[:]
```

- length of a slice: number of elements it contains
- capacity of a slice: number of elements in underlying array, counting from 1st element in slice

**Make: creating a slice**

```go
a := make([]int, 5) // len(a)=5
b := make([]int, 0, 5) // len(b)=0, cap(b)=5
```

**Append: add to a slice**

```go
func append(s []T, vs ...T) []T
```

If the backing array of `s` is too small to fit all given values a bigger array will be allocated.

**Range**

```go
for index, value := range arr {
	fmt.Println(index, value)
}
```


