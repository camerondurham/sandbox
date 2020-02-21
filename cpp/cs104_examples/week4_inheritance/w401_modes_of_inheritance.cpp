#include<iostream>
using namespace std;

class Parent
{
    public:     int pub;
                virtual void test() = 0;
    protected:  int pro;
    private:    int pri;
};

class PublicChild : public Parent
{
    public:
        // pub - YES
        // pro - YES
        // pri - NO
                 void test();
        void access(){ int i = pub + pro;}
};

class ProtectedChild : protected Parent
{
    public:
        // pub - YES
        // pro - YES
        // pri - NO
                 void test();
        void access(){ int i = pub + pro;}
};

class PrivateChild : private Parent
{
    public:
        // pub - YES
        // pro - YES
        // pri - NO
                 void test();
        void access(){ int i = pub + pro;}
};

void Parent::test(){printf("test");}

void ProtectedChild::test(){printf("test");}

void PublicChild::test(){printf("test");}

void PrivateChild::test(){printf("test");}

int main()
{
    PublicChild pubC;
    ProtectedChild proC;
    PrivateChild priC;
    Parent p;

    pubC.access();
    printf("pubC: %d\n",pubC.pub);

    proC.access();
    /* printf("proC: %d\n",proC.pub); */

    priC.access();
    return 0;
}
