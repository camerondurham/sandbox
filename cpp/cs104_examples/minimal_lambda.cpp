#include<iostream>
int main()
{
  int i(0);
  [&i](auto f){
    f();
  }([&i](){ std::cout << "test " << i++ << "\n"; });
}