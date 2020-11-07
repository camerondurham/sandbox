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
import "fmt"
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

}
```