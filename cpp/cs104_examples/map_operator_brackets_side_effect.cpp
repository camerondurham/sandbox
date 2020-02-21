#include<map>
#include<iostream>
#include<string>
using namespace std;

int main()
{
    map<char, int> mMap1;
    map<int, char> mMap2;
    map<int, string> mMap3;
    // prints: 0  ^@ ""
    // since these are the default types for char and int when using operator[]
    cout  << mMap1['c'] << "  " << mMap2[2] << "  " << mMap3[2] << "\n";

}
