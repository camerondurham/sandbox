#include<string>
#include<iostream>

void helper(std::string prefix, std::string curr)
{
    if(!prefix.size()) std::cout << curr << '\n';

    for(unsigned int i = 0; i < prefix.size(); ++i)
    {
        std::string str(prefix);
        std::string next(curr);
        str.erase(str.begin() + i);
        next.push_back(prefix[i]);
        helper(str,next);
    }
}

void allPermutations(std::string str){
    helper(str, "");
}

int main()
{
    // print all unique combinations of the string
    // helper("ABCDE", "");
    allPermutations("ABC");
    allPermutations("ABCDE");
}
