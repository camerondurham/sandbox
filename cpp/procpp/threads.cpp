#include<thread>
#include<iostream>
using std::cout;
int main(int argc, char** argv)
{
  int numberOfThreads = std::thread::hardware_concurrency();
  cout <<  numberOfThreads << '\n';
  return 0;
}