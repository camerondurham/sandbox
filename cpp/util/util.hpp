#include<iostream>
#include<vector>
#include<unordered_set>
#include<unordered_map>
#include<string>
#include<stack>
#include<queue>
#include <numeric>

struct TreeNode {
int val;
TreeNode *left;
TreeNode *right;
TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Util{
	public:
		static void print_vec(std::vector<int> v){
			for(int item : v){
				std::cout << item << "  ";
			}
			std::cout << "\n";
		}
        static void print(std::string s, bool newline=true)
        {
            std::cout << s;
            if(newline) std::cout <<"\n";
        }

};

template <class T>
static void printall(std::vector<T> v, bool newline=false)
{
  for(auto it : v)
  {
    char c = newline ? '\n' : ' ';
    std::cout << it << c;
  }
  std::cout << '\n';
}

// TODO overload << operator to print vector of vectors
