# CS104 HW4: Interpreter Design

## Concept

**Interpreter:**
Reads instructions and directly executes instead of creating an executable.

Interpreted Languages:
* `Python`
* `BASIC`
* `Javascript`

Interpreters usually have the following process:
1. parse the source code
2. perform its behavior directly


Two different phases:

* "compile-time" (parsing the program)
* "runtime" (executing the BASIC instructions)


## Data structures

Students are recommended to use the following D/S:

- Integer Variables: `map<string,int>`
- Array Variables: `map<string, map<int,int>>`
- Lines: `map<int,Command*>`

## Program runtime:

Define discrete unit of program to be able to execute and run programs: a line

Runs sequentially, best way to store that?
* ordered map

**Command Flow**: where to start and how to keep track of program progress

Need to change line number you're executing for these lines:

* `GOSUB`
* `RETURN`
* `GOTO`
* `END`

For this command, only change to LINEJ if expression is true:

**Note:** some students were getting issues since they would always
jump to LINEJ and not check the expression.

* `IF <BEXP> THEN <LINEJ>`

For all other commands, increment the lin


## Examples

```
1 LET ANAKIN ( 5 + ( A[0] + 7))
2 GOSUB 6
3 PRINT ANAKIN
4 PRINT PADME
5 END
6 LET ANAKIN 2
7 LET PADME 3
8 RETURN
9 LET A[0] 19
```



How does this run?

How do you keep track of where to return to from GOSUB's?


Another example:

How to move iteratively through the program and randomly access by a given line?

```
1 IF A[5] > (7 + 2) THEN 4
2 LET A[5] (A[5] + 1)
3 GOTO 1
4 PRINT A[5]
```


Other examples from bytes:

```
1 GOTO 3
2 END
3 GOTO 2
```

No matching gosub for return on line 7
```
1 GOSUB 6
6 GOSUB 7
7 RETURN
```


Nested GoSub example: print squares
```
1 LET X 0
2 LET X (X+1)
3 IF X > 10 15
4 IF X > (X * X)
5 LET X (X+1)
```

```
1 LET A 1
2 LET C 8
3 GOSUB 6
4 LET ARR[(C/A)] 2
5 END
6 LET A 0
7 RETURN
```

### Errors:

Parsing errors in hw2:
* invalid arguments
* expected integer expression, etc
* too may parens

Runtime exceptions in hw4:
* gosub/return: no return statement
* division-by-zero errors
* gosub/goto: invalid line numbers

Tips for parsing expressions:
* make helper functions
* test functions in small cpp files or on cpp.sh


