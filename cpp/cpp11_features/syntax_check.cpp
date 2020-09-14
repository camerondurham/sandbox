#include<map>
#include<iostream>
#include<string>
int main()
{
  std::map<std::string, std::string> op {{"Hello", "Goodbye"}, {"Constant", "Dynamic"}, {"Hot", "Cold"}};

  // write an iterator for the map
  // answer
  auto it = op.begin();

  // use decltype to write the same thing
  // answer
  decltype(it) it2 = op.begin();


  // write a range based for-loop that doesn't copy by value

  for(
          std::map<std::string, std::string>::const_iterator pair = op.begin();
          pair != op.end();
          pair++
     )
  {
      std::cout << pair->first << ":" << pair->second << "\n";

  }

  // answer
  for(const auto& pair : op)
  {
      std::cout << pair.first << ":" << pair.second << "\n";

  }

  return 0;
}
