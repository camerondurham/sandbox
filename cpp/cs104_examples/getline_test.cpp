#include<sstream>
#include<iostream>
#include<string>
using namespace std;
int main()
{
    stringstream s1("A\nB\nC\n");
    string str;
    while(getline(s1,str))
    {
        char c;
        s1>>c;
        cout << c << '\t' << str << '\n';
    }

    cout << '\n';
    stringstream s2("A\nB\nC\n");
    while(!s2.fail())
    {
        char c;
        s2 >> c;
        cout << c << '\n';
    }
}