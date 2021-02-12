#include<iostream>
#include<map>
#include<unordered_map>
#include<set>
#include<unordered_set>
#include<string>

int main()
{
    std::map<size_t,std::string> map;
    std::unordered_map<size_t,std::string> umap;
    std::set<size_t> set;
    std::unordered_set<size_t> uset;
    const size_t size = 10;

    // inserting in reverse order
    for(size_t i = 0; i < size; ++i)
    {
        map[size - i] = std::to_string(i);
        umap[size - i] = std::to_string(i);
        set.insert(size - i);
        uset.insert(size - i);
    }

    std::cout << "\nOrdered Map:\n";
    for(std::map<size_t,std::string>::iterator it = map.begin(); it != map.end(); ++it)
    {
        // prints out in ascending order since we use default ordering with a operator<
        std::cout << "( " << it->first << ",\"" << it->second << "\")\n";
    }

    std::cout << "\nUnordered Map:\n";
    for(std::unordered_map<size_t,std::string>::iterator it = umap.begin(); it != umap.end(); ++it)
    {
        // ordering cannot be assumed since an unordered map uses a hash map (random key ordering)
        std::cout << "( " << it->first << ",\"" << it->second << "\")\n";
    }

    std::cout << "\nOrdered Set:\n";
    for(std::set<size_t>::iterator it = set.begin(); it != set.end(); ++it)
    {
        std::cout << *it << "\n";
    }

    std::cout << "\nUnordered Set:\n";
    for(std::unordered_set<size_t>::iterator it = uset.begin(); it != uset.end(); ++it)
    {
        std::cout << *it << "\n";
    }
}
