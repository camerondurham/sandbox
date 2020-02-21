#include <vector>
#include <unordered_map>
#include <iostream>
#include <map>
using namespace std;
int main()
{
    std::vector<const char* > vec = {"I", "love", "cs104"};
    std::unordered_map<char, std::vector<const char*>> _umap;
    _umap['I'] = vec;

    for(const char* str : vec)
    {
        std::cout << str << " " << std::endl;
    }

    map<string, int> _map;
    ;
    _map["the answer to everything"] = 42;
    for(map<string, int>::iterator it = _map.begin(); it!= _map.end(); ++it)
    {

    }




}
