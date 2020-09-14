#include <iostream>
#include<chrono>
#include<ctime>
#include<cmath>
#include<memory>

struct Timer
{
        Timer(){ start = std::chrono::steady_clock::now(); };
        ~Timer()
        {
            end = std::chrono::steady_clock::now();
            elapsed_seconds = end - start;
            std::cout << "Timer: " << elapsed_seconds.count() << "s\n";
        }

        /* decltype(std::chrono::steady_clock::now()) start; */
        std::chrono::time_point<std::chrono::steady_clock> start;
        std::chrono::time_point<std::chrono::steady_clock> end;
        std::chrono::duration<double> elapsed_seconds;
};

long fibonacci(unsigned n)
{
    if (n < 2) return n;
    return fibonacci(n-1) + fibonacci(n-2);
}

int main()
{
    auto timer = std::make_unique<Timer>();
    std::cout << "Unique pointer demo\n";


    {
        // local timer created
        auto timer = std::make_unique<Timer>();
        std::cout << "f(42) = " << fibonacci(42) << '\n';
        // unique_ptr destructor is called at the end of this block
    }
}
