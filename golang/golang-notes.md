# Golang

## Tour of Go

Exported names
 - names that begin with a capital letter are exported from a package. ex: `math.Pi`

Functions

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

