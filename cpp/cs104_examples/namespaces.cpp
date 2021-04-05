#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
#include<string>

void for_each(const std::vector<int>& values, const std::function<void(int)>& func)
{
  for(int val : values)
    func(val);
}

namespace apple {
  void print(const std::string& text)
  {
    std::cout << text << std::endl;
  }
}

namespace orange {
  void print(const char* text){
    std::string temp = text;
    std::reverse(temp.begin(), temp.end());
    std::cout << temp << std::endl;
  }
}

using namespace apple;
using namespace orange;   // now using orange's version of functions

int main()
{

  // without namespace apple
  print("Hello");

  std::vector<int> values  = {1, 4, 2, 5, 3};
  auto it = std::find_if(values.begin(), values.end(), [](int value) { return value > 3; });
  std::cout << *it << std::endl;

  int captured = 5;
  auto lambda = [=](int value) { std::cout << "Captured: " << captured << std::endl; };

  for_each(values, lambda);
  return 0;

}
