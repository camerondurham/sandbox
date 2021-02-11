#include <stdio.h>
#include <numeric>
#include <string>
#include <vector>
int main() {

  std::vector<int> v({1,1,2,3,5,8});
  auto s = std::accumulate(std::next(v.begin()), v.end(), std::to_string(v[0]),
                           [](std::string s, int a) {
                             return std::move(s) + ',' + std::to_string(a);
                           });
  printf(s.c_str());
}