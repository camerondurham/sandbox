#include <iostream>

struct A { double x; };
const A* a;

decltype(a->x) y;       // type of y is double (declared type)
decltype((a->x)) z = y; // type of z is const double& (lvalue expression)

template<typename T, typename U>
auto add(T t, U u)  -> decltype(t+u)    // return type depends on template parameters, you don't NEED decltype here
                                        // return type can be deduced since C++14
{
    return t+u;
}


// https://en.wikipedia.org/wiki/Decltype

int& foo(int& i){ return i; }
float foo(float& f){ return f*f; }

template <class T>
auto transpadent_forwarder(T& t) -> decltype(foo(t))
    // you need decltype here to grab the return type
    // info from return type of the overloaded foo(t)
{
    return foo(t);
}


int main()
{
    int i = 33;
    double d = 2.2;

    std::cout << add(i,d) << "\n";
    std::cout << add(i,i) << "\n";
    std::cout << add(0.0f, 2.0f) << "\n";

    decltype(i) j = i * 2;

    std::cout << "i = " << i << ", "
              << "j = " << j << '\n';

    auto f = [](int a, int b) -> int
    {
        return a * b;
    };

    decltype(f) g = f; // the type of a lambda function is unique and unnamed
    i = f(2, 2);
    j = g(3, 3);

    std::cout << "i = " << i << ", "
              << "j = " << j << '\n';
}
