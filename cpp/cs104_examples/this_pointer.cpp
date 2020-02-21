#include <iostream>

using namespace std;

/*
 *  Simple example made on 11-30-2019 for CS104 office hours in Leavy Library!
 *  Meant to clarify what this-> pointer actually does in classes where
 *  a member variable is inherited and duplicated in the subclass.
 *
 *  Read more at: https://en.cppreference.com/w/cpp/language/this
 *
 */

class A {
    public:
    int root = 'A';
    void setSuperRoot(int val){
        root = val;
    }

    int getSuperRoot(){
        return root;
    }
};

class B : public A {
    public:
    int root = 'B';
    void setRootThis(int val){
        this->root = val;
    }

    void setRoot(int val){
        root = val;
    }
    int getRoot(){
        return root;
    }

    int getThisRoot(){
        return this->root;
    }

    int getSuperRootB(){
        return A::root;
    }
};

int main(){
    B b;
    b.setRootThis(7);
    cout << "A root: " << b.getRoot() << " B this->root: " << b.getThisRoot() << " A root: " << b.getSuperRootB() << "\n";
    b.setRoot(2);
    cout << "A root: " << b.getRoot() << " B this->root: " << b.getThisRoot() << " A root: " << b.getSuperRootB() << "\n";
    b.setSuperRoot(42);
    cout << "A root: " << b.getRoot() << " B this->root: " << b.getThisRoot() << " A root: " << b.getSuperRootB() << "\n";
}
