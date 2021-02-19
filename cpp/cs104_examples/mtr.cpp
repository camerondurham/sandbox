#include<iostream>
#include<string>
using namespace std;

class Question {
public:
  Question(int v) : val(v) { }
  virtual ~Question() { cout << "d1" << endl; }
  virtual string studentResponse() = 0;
  int getValue() { return val; }
private:
  int val;
};

class NonTrivialQuestion : public Question {
public:
  NonTrivialQuestion() : Question(10) { }
  NonTrivialQuestion(int v) : Question(v) { }
  ~NonTrivialQuestion() { cout << "d2" << endl; }
  string studentResponse() { return "I got this!"; }
  int getValue() { return 15 + Question::getValue(); }
};

class DifficultQuestion : public NonTrivialQuestion {
public:
  DifficultQuestion() : NonTrivialQuestion() { }
  ~DifficultQuestion() { cout << "d3" << endl; }
  string studentResponse()
  { return "When are office hours?"; }
};

int main()
{
  Question* p[2];
  p[0] = new NonTrivialQuestion(15);
  p[1] = new DifficultQuestion;
  for(int i=0; i < 2; i++){
    cout << p[i]->getValue() << endl;
    cout << p[i]->studentResponse() << endl;
  }
  NonTrivialQuestion* q[2];
  q[0] = new NonTrivialQuestion(15);
  q[1] = new DifficultQuestion;
  for(int i=0; i < 2; i++){
    cout << q[i]->getValue() << endl;
    cout << q[i]->studentResponse() << endl;
  }
  delete p[1];
  return 0;
}
/*
root@docker:/work/sandbox/cpp/cs104_examples$ g++ -std=c++11 -Wall mtr.cpp -o mtr
root@docker:/work/sandbox/cpp/cs104_examples$ ./mtr
15
I got this!
10
When are office hours?
30
I got this!
25
When are office hours?
d3
d2
d1
*/