#include<functional>
#include<iostream>
#include<numeric>
#include<string>
int main() {
  std::vector<std::vector<int>> v{{1,2,3},{4,5,6},{7,8,9}};
  int n = std::accumulate(v.begin(), v.end(), 0, [](int nn, std::vector<int> vec){
    int inner = std::accumulate(vec.begin(), vec.end(), 0);
    return nn + inner;
  });

  std::cout << "Total is: " << n << '\n';

  std::string s = std::accumulate(v.begin(), v.end(), std::string{}, [](std::string strOuter, const std::vector<int>& vec) {
    std::string line = std::accumulate(std::next(vec.begin()), vec.end(), std::to_string(vec[0]), [](std::string strInner, int i){
      return std::move(strInner) + ',' + std::to_string(i);
    });
    return std::move(strOuter) + '\n' + line;
  });

  std::cout << s << '\n';
}