#include<iostream>
#include<string>
#include<fstream>
#include<sstream>
#include<vector>
int main(int argc, char** argv)
{
  std::fstream file("train.txt");
  std::vector<std::string> v;
  std::string line;
  file >> line;
  std::cout << line << std::endl;
  while(getline(file, line))
  {
    std::stringstream ss(line);
    ss >> line;
    v.push_back(line);
    ss >> line;
    for(;!ss.fail();)
    {
      v.push_back(line);
      ss >> line;
    }
  }

  for(std::string s : v)
  {
    std::cout << s << "\n";
  }

}