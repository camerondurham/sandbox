# Regular Expressions

Token definitions in lex are given using *regular expressions*.

---

Types of Regular Expressions

A string of normal characters matched directly 

```cpp
// Matches endline
\n
// Matches word new
new
// Quotes are optional, but I usually use them
// Matches delete
"delete"
```

The `[]` operator

`[]` allows the regex to match any of the characters inside brackets

```cpp
// Matches aac, abc, or acc
a[abc]c

// A hyphen means any characters within that range
// Matches aac, abc, acc, adc, ..., azc
a[a-z]c

// You can combine multiple ranges
// Matches the same as above, plus aAc, ..., aZc
a[a-zA-Z]c
```

The `*` operator - The "Kleen Closure"

The `*` means the precedding character can appear **0 or more times**.

```cpp
// Matches ac, abc, abbc, abbbc, ...
ab*c
// Can be combined with square brackets
// Matches a followed by zero or more digits
a[0-9]*
```


The `+` operator

The element **must appear at least once time**, similar to the `*` operator.

```cpp
// Matches ac, abc, abbc, abbbc, ...
ab*c

// Can be combined with square brackets
// Matches a followed by zero or more digits
a[0-9]*
```

The `.` operator

Matching anything, any character you want for that slot:

```cpp
// Matches ac, abc, abbc, abbbc, ...
ab*c

// Can be combined with square brackets
// Matches a followed by zero or more digits
a[0-9]*
```

If you don't want to use an operator, you must quote it or escape it:


```cpp
// Use quotes around the literal
"+"

// Use the backslash to escape the symbol
\+
```