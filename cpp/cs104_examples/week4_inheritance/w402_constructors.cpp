#include<iostream>
using namespace std;

class A
{
    public: A() {printf("A\n");}
};

class B
{
    public: B() {printf("B\n");}
};

class C: public B, public A
{
    public: C() {printf("C\n");}
};

int main()
{
    C c;
    return 0;
}


