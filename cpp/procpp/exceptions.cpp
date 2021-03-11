#include<vector>
int main()
{
  std::vector<int> v(10);
  // throw "";
  v.at(40);
  // when running with g++
  // g++ -std=c++11 -fno-exceptions -Wall exceptions.cpp -o exceptions.o
  // terminate called after throwing an instance of 'std::out_of_range'
  //   what():  vector::_m_range_check: __n (which is 40) >= this->size() (which is 10)
  // aborted

  // relevant SO question: https://stackoverflow.com/questions/7249378/disabling-c-exceptions-how-can-i-make-any-std-throw-immediately-terminate
  // and answer: https://stackoverflow.com/a/7249442/4676641

  return 0;
}