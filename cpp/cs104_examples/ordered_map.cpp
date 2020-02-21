#include<iostream>
#include<map>
#include<unordered_map>
#include<string>
#include<vector>

int main()
{
    std::map<size_t,std::string> map;
    std::unordered_map<size_t,std::string> umap;

    std::vector<std::string>  lines =
    {
      "1 LET ANAKIN 1",
      "10 PRINT (ANAKIN + 2)",
      "8 GOTO 10",
      "9 PRINT ANAKIN"
    };

    for(size_t idx = 0; idx < lines.size(); ++idx)
    {
        std::string str(lines[idx]);
        size_t i = 0, val = 0;
        while(str[i] != ' ' && i < str.size())
        {
          val = 10 * val + (((unsigned long)str[i++]) - ((unsigned long)'0'));
        }
        std::string sub = str.substr(i+1,str.size() - i);
        std::cout << "Line #: " << val << "\t" << "Command: " << sub << "\n";
        map[val] = sub;
        umap[val] = sub;
    }

    std::cout << "\nOrdered Map:\n";

    for(std::map<size_t,std::string>::iterator it = map.begin(); it != map.end(); ++it)
    {
        std::cout << "( " << it->first << ",\"" << it->second << "\")\n";
    }

    std::cout << "\nUnordered Map:\n";
    for(auto it = umap.begin(); it != umap.end(); ++it)
    {
        std::cout << "( " << it->first << ",\"" << it->second << "\")\n";
    }


}
