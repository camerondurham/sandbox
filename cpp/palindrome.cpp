#include "leetcode/util/util.hpp"
#include <assert.h>
using std::string;
using std::cout;
bool palindrome(string s)
{
    size_t n = s.size();
    for(size_t i = 0; i < n; ++i)
    {
        if(s[i] != s[n - i - 1]) return false;
    }
    return true;
}

int main()
{
    cout << "Beginning testing...\n";
    assert(palindrome("cat") == false);
    assert(palindrome("za") == false);
    assert(palindrome("123iooo321") == false);
    assert(palindrome("12321") == true);
    assert(palindrome("gaccag") == true);
    assert(palindrome("gacacag") == true);
    assert(palindrome("c") == true);
    cout << "SUCCESS!\n";
}
