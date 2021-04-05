#include<iostream>
#include<map>
#include<set>
#include<string>
int main() {
  std::map<std::string, std::set<std::string>>::iterator it;
  std::map<std::string, std::set<std::string>> training;
  for(int i = 0; i < 10; ++i)
  {
    std::string str("test" + std::to_string(i));
    training[str].insert("item" + std::to_string(i));
  }

  for (it = training.begin(); it != training.end(); ++it)
  {
    std::cout << "key: " << it->first << std::endl;
    std::set<std::string>::iterator setIt;
    for (setIt = it->second.begin(); setIt != it->second.end(); ++setIt)
    {
      std::cout << *setIt << std::endl;
    }
  }
}
