#include<vector>
#include<iostream>
#include<string>
using namespace std;


template <typename X, typename Y>
auto add(X x, Y y) -> decltype(x + y) {
    return x + y;
}

int main()
{

    auto s = "I love CS104\n";

    auto vec = { 1, 2, 3, 4 };

    auto sudokuCell = { vec, { 2, 4, 1 }, { 8, 9, 7 } };

    for(auto v : vec)
    {
        cout << v << " ";
    }

    vector<string> strings = {"Heap", "Hash Table", "Priority Queue"};
    for(const auto& str : strings)
    {
        cout << str << "\n";
    }


    cout << endl;

    auto f = [](int a, int b) -> int
    {
        return a * b;
    };

    decltype(f) g = f; // just use the default return value
    auto p = f;


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


    return 0;
}
