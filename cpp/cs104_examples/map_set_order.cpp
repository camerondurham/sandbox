#include<iostream>
#include<map>
#include<string>

int main()
{
    std::map<size_t,std::string> map;
    const size_t size = 10;

    for(size_t i = 0; i < size; ++i)
    {
        map[size - i] = std::to_string(i);
    }

    std::cout << "\nOrdered Map:\n";

    for(std::map<size_t,std::string>::iterator it = map.begin(); it != map.end(); ++it)
    {
        std::cout << "( " << it->first << ",\"" << it->second << "\")\n";
    }

}
