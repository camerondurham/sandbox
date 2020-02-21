#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

class Solution {
    public:
        void swap(vector<int> v, int i1, int i2){
            cout << "\n" << v[i1] << " " << v[i2] << "\n";
            iter_swap(v.begin() + i1, v.begin() + i2);
            cout << "\n" << v[i1] << " " << v[i2] << "\n";
        }

};

int main() {
    Solution soln;
    vector<int> vec {1,2,3,4,5};

    soln.swap(vec, 1, 2);

    return 0;
}
