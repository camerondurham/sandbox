#include <iostream>
using namespace std;
class classA {
    public:virtual void f1() = 0;
    protected:virtual void f2() { cout << "A f2  " << endl;}
    private:void f3() { cout << "A f3 " << endl;}};

class classB : public classA {
    public:void f1() {cout << "B f1 " << endl;}
};
class classC: protected classB {
    public:void f1() { f2();}
    protected:void f2() {
                  classB::f2();cout << "C f2 ";
                  classA::f2();}
};

int main(){
    classA* a;
    classB* b = new classB();
    classC* c = new classC();
    classC* c1;
    c1 = a;

}
