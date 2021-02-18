#include<iostream>
#include<vector>
#include<string>
#include<numeric>
#include<algorithm>
int main() {
  std::vector<int> v(10000);
  std::vector<int> p;
  std::iota(v.begin(), v.end(), 2);
  std::for_each(v.begin(), v.end(), [&p](int i){
    bool prime = true;
    for(int j : p){
      if(i % j == 0){
        prime = false;
        break;
      }
      if(j * j > i) break;
    }
    if(prime) p.push_back(i);
  });
  std::cout << std::accumulate(std::next(p.begin()), p.end(), std::to_string(p.at(0)), [](std::string ss,int i){
  return std::move(ss)+','+std::to_string(i);
  });
}