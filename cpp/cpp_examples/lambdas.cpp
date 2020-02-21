#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
// reference https://en.cppreference.com/w/cpp/language/lambda

void ForEach(std::vector<int>& values, const std::function<void(int&)>& func)
{
  for(int& val : values)
    func(val);
}

int main()
{
  std::vector<int> values  = {1, 4, 2, 5, 3};
  //auto it = std::find_if(values.begin(), values.end(), [](int value) { return value > 3; });
  //std::cout << *it << std::endl;

  //int captured = 5;
  //auto lambda = [=](int value) { std::cout << "Captured: " << value << std::endl; };
  auto div2 = [=](int &value) { value /= 2; };
  auto mul10 = [=](int &value) { value *= 10; };
  auto print = [=](int &value) { std::cout <<  value << std::endl; };

  ForEach(values, print);
  std::cout << "\n\n\n";

  ForEach(values, div2);
  ForEach(values, print);
  std::cout << "\n\n\n";
  ForEach(values, mul10);
  ForEach(values, print);

  return 0;

}
