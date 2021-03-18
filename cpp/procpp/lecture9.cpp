#include<iostream>
#include <cinttypes>
#include<utility>
#include<vector>
// TODO: add design pattern code?

// Template Metaprogramming lecture

// Constexpr version
// you can use constexpr to evaluate values at compile time
// limited for specific step values
constexpr uint64_t fib(uint64_t n)
{
  if(n<2)
  {
    return n;
  }
  else
  {
    return fib(n-2) + fib(n-1);
  }
}

uint64_t fib_iter(uint64_t n)
{
  std::vector<uint64_t> results(n+1);
  results[0] = 0;
  results[1] = 1;
  for(size_t i = 2; i < n+1; ++i)
  {
    results[i] = results[i - 1] + results[i-2];
  }
  return results[n];
}


// template version
// NOTE: this will only work if `N` is known at compiletime
template<uint64_t N>
struct Fib
{
  // (recursive case)
  static const uint64_t result = Fib<N-2>::result + Fib<N-1>::result;

};

// Specialization / base case where N = 1
template<>
struct Fib<1>
{
static const uint64_t result = 1;
};

template<>
struct Fib<0>
{
static const uint64_t result = 0;
};

template <typename T>
T max(T a, T b)
{
  return ((a>b) ? a : b);
}

// Template Specialization
// removes one or more template parameters
template<>
std::string max<std::string>(std::string a, std::string b)
{
  // do something specific
}

// Tuple:

template <typename... Args>
std::tuple<Args...> ParseStr(std::vector<std::string>& paramV);

template <>
inline std::tuple<int> ParseElem<int>(const std::string&  paramV)
{
  return std::make_tuple(std::stoi(paramV));
}


template <>
inline std::tuple<std::string> ParseElem<std::string>(const std::string&  paramV)
{
  return std::make_tuple(paramV);
}

// needs to say inline becasue it's not a member function
// specializations need to be inlined if they're  not member functions
// otherwise, linker error!
template <>
inline std::tuple<> ParseStr<>(std::vector<std::string>& paramV)
{
  return std::make_tuple();
}



int main(int argc, char** argv)
{
  // fails because exceeds compiler step limit
  // constexpr uint64_t f = fib(40);
  uint64_t f = Fib<40>::result;
  uint64_t f2 = fib_iter(40);

  std::cout << f << std::endl;

  std::cout << f2 << std::endl;

  std::cout << "max(1, 5) " << max(1, 5) << std::endl;

  // autodeduction only works when both types are needed
  std::cout << "max(1, 5.0) " << max<double>(1, 5.0) << std::endl;

}