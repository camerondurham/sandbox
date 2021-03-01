#include <fstream>
#include <iostream>
#include <string>
int main()
{
  std::ofstream file("filename.txt");
  file << "fuck i hate writing to files in c++ /s";
  file.close();
  std::ifstream file2("filename.txt");
  std::string line;
  std::getline(file2, line);
  std::cout << line << '\n';
}