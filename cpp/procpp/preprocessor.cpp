#include<iostream>
int main(int argc, char** argv)
{
#ifdef DUCK
//  g++ -std=c++11 -Wall -DDUCK preprocessor.cpp -o preprocessor.o && ./preprocessor.o
  std::cout << "I'm a duck!!\n";
#else
//  g++ -std=c++11 -Wall preprocessor.cpp -o preprocessor.o && ./preprocessor.o
  std::cout << "I'm not a duck\n";
#endif
}