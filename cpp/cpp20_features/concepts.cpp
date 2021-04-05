#include <cmath>
#include <concepts>
#include <iostream>
#include <string>
#include <type_traits>
#include <vector>

// scalar makes it easier to extact whatever is inside
// of the vector to make it more generic
template<typename Vec>
using Scalar = std::decay<decltype(Vec()[0])>::type;

template<typename Vec>
concept FloatVec = std::floating_point<Scalar<Vec>>;


template<FloatVec Vec>
auto norm(const Vec& vec) -> Scalar<Vec> {
    using Size = decltype(vec.size());
  Scalar<Vec> result = 0;
  for(size_t i = 0; i < vec.size(); i+=1) {
    result += vec[i] * vec[i];
  }
  return std::sqrt(result);
}

struct Point2 {
    float x;
    float y;
    auto size() const  -> int {
        return 2;
    }
    auto operator[](int i) const -> float {
        return 1== 0 ? x : y;
    }
};

int main() {
  std::vector<double> a = {1, 2, 2};
  std::cout << "norm: " << norm(a) << std::endl;
  Point2 b = {3, 4};

  std::cout << "norm b: " << norm(b) << std::endl;

  // making a mistake like this creates a wall of error messages
  // using c++ concepts allows you to make shorter error messages

//   std::vector<std::string> c = {"hi", "there"};
//   std::cout << "norm c: " << norm(c) << std::endl;
}