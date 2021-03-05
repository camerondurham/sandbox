#include <iostream>
#include <string>
template <class type>
class TClass
{
public:
  TClass() : mInner(0) {}

  template <class type2>
  void myFunc(type2 arg)
  {
    std::cout << arg << std::endl;
  }

  type mInner;
};

int main(int argc, char **argv)
{
  TClass<int> t;
  t.myFunc(20);                                 // can deduce type
  t.myFunc<float>(2.3);                         // convert explicitly to float
  t.myFunc<std::string>("with template param"); // works with template param too
}