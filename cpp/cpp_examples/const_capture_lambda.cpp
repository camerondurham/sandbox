int main()
{
  const int a = 1;
  [&a](){ a = 2; }();
}

/*
Fails to compile:
$ g++ -std=c++17 -Wall const_capture_lambda.cpp -o const_capture_lambda
const_capture_lambda.cpp: In lambda function:
const_capture_lambda.cpp:4:13: error: assignment of read-only reference 'a'
   [&a](){ a = 2; }();
             ^
*/