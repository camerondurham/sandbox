## Range Based For Loops

We used range based for loops in an example for `auto`. You can use the following syntax to execute a loop over a range.

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


for(int i : {2, 3, 4} )
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
