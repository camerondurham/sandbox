#include<iostream>

class Test{
  public:
  int var = 0;
  const int cV(){return var;}
  const int& cR(){return var;}
  int& cA(){return var;}
  void printVar(){std::cout<<"Var is: " << var<< std::endl;}
  void incrVar(){var++;}
};
int main()
{
  Test* t = new Test();
  int num = t->cV();
  num++;
  t->printVar();
  std::cout << "Num is " << num << std::endl;


  const int& ref = t->cR();
  //ref++;
  t->printVar();
  std::cout << "Ref is " << ref << std::endl;
  t->incrVar();
  t->printVar();
  std::cout << "Ref is " << ref << std::endl;

  int a = t->cA();
  a++;
  t->printVar();
  std::cout << "A is " << a << std::endl;

  delete t;
  return 0;
}
