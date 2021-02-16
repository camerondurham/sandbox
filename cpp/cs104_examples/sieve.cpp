#include<iostream>
#include<vector>
#include<string>
#include<numeric>
int main() {
  std::vector<int> v;
  for(int i = 2; i < 1000000; i++){
      bool prime = true;
      for(int j : v){
        if (i % j == 0){
          prime = false;
          break;
        }
        if (j * j > i) break;
      }
      if(prime) v.push_back(i);
  }
  std::cout << std::accumulate(std::next(v.begin()), v.end(), std::to_string(v.at(0)), [](std::string ss,int i){
  return std::move(ss)+','+std::to_string(i);
  });
}