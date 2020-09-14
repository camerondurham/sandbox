## `auto` and `decltype`


We know you all love C++, but sometimes the verbose types can get annoying and slow down programming.

For example, here's something you might've had to deal with:

```cpp
std::unordered_map<std::string, std::vector<std::pair<std::string, double>>>
```

Ok, that might be an exaggeration, but hopefully you get the point. Wouldn't it be nice if you didn't
have to type all that? You probably already know something about `auto` since you've seen it in our
skeleton code. Now we'll cover when it's recommended to use it, and how it works.

### What is `auto'?

`auto` was added to C++11 as a **placeholder type specifier**. That mean the type of the variable
declared will be automatically deduced from its initializer. To use `auto`, simply use `auto`
to declare and initialize a variable instead of giving a type:

```cpp
auto str = "I love C++";
auto vec = { 3, 5, 6 };
auto sudokuCell = { vec, { 2, 4, 1 }, { 8, 9, 7 } };
```

**NOTE:**

Because `auto` determines the type from the variable's initialization, you have to declare and initialize
the variable at the same time. The example below will throw a compiler error.

```cpp
auto num;
num = 2;
```

Now let's talk about how `auto` works. At compile time, the type of the initializer is used to determine
what type the variable is. The compiler already has to check the type of the right-hand side to make sure you're
not doing something illegal, so why not let it assign that type to the variable? The benefit of this is
that using `auto` has no effect on runtime since all types are deduced at compile time.

## Customizing the type deduction

A common use of `auto` is when iterating over some data structure like the overly complex one declared
above. You can add `const` and/or `&` to auto to modify the deduced type. In the example below, if
you didn't use `const auto&` instead of `auto`, you're making an expensive copy by value of the
vector's contents.

```cpp
vector<string> strings = {"Heap", "Hash Table", "Priority Queue"};
for( const auto& str : strings )
{
    cout << str << "\n";
}
```

### What is `decltype`?

The decltype operator returns the *declared type* of the arguments. It's sometimes useful when you use lambda functions when
the actual return type isn't always clear. Below is a simple example of how you can use it.

```cpp
int i = 104;
decltype(i) j = i * 2 + 62; // this is an int
```

As a slightly more realistic example, take the following template to add two numbers.
You want add(2, 1.2) to return a double and add(2, 1) to return an int. That's not really possible to specify this kind of
behavior without auto and decltype. Instead, you can use decltype to determine the return type for this function.

Example from [cpprefererence](https://en.cppreference.com/w/cpp/language/decltype):

```cpp
template<typename T, typename U>
auto add(T t, U u) -> decltype(t + u) // return type depends on template parameters
                                      // return type can be deduced since C++14
{
    return t+u;
}
```

You might be asking what the difference between auto and decltype by now. The main difference is that you can
use decltype if you just want the type of some expression or variable. If you want to customize the type of
the variable being initialized (i.e. using const auto&), you should use auto. Also, it's obviously easier to write out auto.

## Range Based For Loops

We used range based for loops in an example for auto. You can use the following syntax to execute a loop over a range.

```cpp
for ( range_declaration : range_expression )
{
    loop_statement
}
```

- range_declaration is a named variable that represents the elements of the range_expression
- any expression that's a sutible sequence, such as an array or container, or even a braced-init-list

Here are some examples:

```cpp

vector<int> nums = {2, 3, 4};
for (int i : nums)
    cout << i << " ";
cout << "\n";


for(int i : {2, 3, 4})
    cout << i << " ";
cout << "\n";

vector<vector<int>> vec2d = {{0,1,2}, {3,4,5}, {6,7,8}};
for(vector<int> v : vec2d)
{
    for(int i : v)
    {
        cout << i << " ";
    }
    cout << "\n";
}


```

Of course, these range based for loops are another great place to use auto.
