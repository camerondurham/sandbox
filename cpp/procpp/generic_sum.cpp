#include<iostream>

template <typename T>
T SumHelper(T a, T b){
}

template <>
inline bool SumHelper<bool>(bool a, bool b)
{
  return a || b;
}

template <>
inline int SumHelper<int>(int a, int b)
{
  return a + b;
}

template<>
inline uint8_t SumHelper<uint8_t>(uint8_t a, uint8_t b)
{
  return a | b;
}

template <typename T>
T Sum(T a, T b)
{
  return SumHelper<T>(a,b);
}




int main(int argc, char const *argv[]) {
  // Sum using "+" operator on input parameters.
  auto sum_int = Sum(1, 2);
  std::cout << "sum_int: " << sum_int << std::endl;

  // Sum using logical OR of input parameters.
  auto sum_bool1 = Sum(true, true);
  std::cout << "sum_bool1: " << sum_bool1 << std::endl;

  auto sum_bool2 = Sum(false, true);
  std::cout << "sum_bool2: " << sum_bool2 << std::endl;

  auto sum_bool3 = Sum(false, false);
  std::cout << "sum_bool3: " << sum_bool3 << std::endl;

  // Sum using bitwise OR of input parameters.
  uint8_t a = 0b00001111;
  uint8_t b = 0b11110000;

  auto sum_uint8_t = Sum(a, b);
  std::cout << "sum_uint8_t: " << sum_uint8_t << std::endl;
  return 0;
}