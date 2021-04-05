#include<iostream>
#include<vector>

// using a normal function pointers
// void PrintValue(int value)
// {
//   std::cout << "Value: " << value << std::endl;
// }
void ForEach(const std::vector<int>& values, void(*func)(int))
{
  for(int val : values)
    func(val);
}

int main()
{

  std::vector<int> values = {1, 5, 2, 3, 4};

  // using normal function
  // ForEach(values, PrintValue);

  // using anonymous functions
  ForEach(values, [](int val){
      std::cout << "Value: " << val << std::endl;
      });
}
