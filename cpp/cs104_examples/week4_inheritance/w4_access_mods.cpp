#include<iostream>

using namespace std;


// FYI, this is a great guide: https://www.learncpp.com/cpp-tutorial/115-inheritance-and-access-specifiers/
// this too: https://docs.microsoft.com/en-us/cpp/cpp/protected-cpp?view=vs-2019
class Parent {
    public:
        int pub = 1;
        virtual void access();
    protected:
        int pro = 2;
    private:
        int pri = 3;
};

class ProtectedChild : protected Parent {
    public:
        void access();
};

class Child : public Parent {
    public:
        void access();
};


class Grandchild : public Child {
    public:
        void access();
};

class ProtectedGrandchild : protected ProtectedChild {
    public:
        void access();
};

class Default : Parent  // defaults to private inheritance
{
    int priv; // just like this variable defaults to being private
};



void Parent::access()
{
    printf("pub: %d, pro: %d, pri: %d\n", pub, pro, pri);
}

void ProtectedChild::access()
{
    printf("pub: %d, pro: %d, pri: :(\n", pub, pro);
}

void ProtectedGrandchild::access()
{
    printf("pub: %d, pro: %d, pri: :(\n", pub, pro);
}

void Child::access(){
    printf("pub: %d, pro: %d, can't access pri :(\n", pub, pro);
}

void Grandchild::access(){
    printf("pub: %d, pro: %d, can't access pri :(\n", pub, pro);
}

int main(){
    Grandchild g;
    Child c;
    Parent p;

    ProtectedChild pc;
    ProtectedGrandchild pg;

    cout << "Accessing parent: \n";
    p.access();
    cout << "Accessing child: \n";
    c.access();
    cout << "Accessing grandchild: \n";
    g.access();
    cout << "Accessing protected child: \n";
    pc.access();
    cout << "Accessing protected grandchild: \n";
    pg.access();

    // then what is all this protected stuff about??
    // this will work just fine
    printf("p: %d, c: %d, gc: %d\n", p.pub, c.pub, g.pub);

    // this won't work since all data members from Parent become protected
    //printf("pc: %d, gc: %d\n", pc.pub, pg.pub);
    return 0;
}
