#include <iostream>
#include<vector>
#include<unordered_set>
#include<algorithm>
using namespace std;

int solution(vector<int> A){
  vector<vector<int>> dp(A.size() + 1, vector<int>(A.size() + 1, 0));

  for(int i = 1; i <= A.size(); ++i)
  {
    unordered_set<int> ints;
    for(int j = i; j <= A.size(); ++j)
    {
      if(ints.find(A[j-1]) != ints.end())
        ints.clear();
      else
        ints.insert(A[j-1]);
      int currentSize = ints.size();
      int lastSize = dp[i][j-1];
      int lastRow = dp[i-1][j];
      dp[i][j] = std::max(currentSize, std::max(lastSize, lastRow));
    }
  }
  return dp[A.size()][A.size()]; 
}

/*
You want to spend some time in your N-day long vacation on a movie marathon. It's an event that takes place over a number of consecutive days. On each of those days you want to go to the cinema to watch a movie, but you don't want to see any movie more than once. The cinema in your town shows one movie per day. Knowing the schedule for the N days of your vacation, you want to plan the longest possible marathon.

Write a function:

class Solution { public int solution(int[] A); }

that, given an array A consisting of N integers (which represent the IDs of the movies played on each of the N days of your vacation), returns the length of the longest marathon that doesn't feature any movie more than once.

For example, given array A = [1, 2, 1, 3, 4, 3, 5] the function should return 4. The longest marathon starts on the second day of your vacation and lasts for four days, featuring movies [2, 1, 3, 4].

Given array A = [1, 1, 1, 2] the function should return 2, as the longest marathon starts on the third day of your vacation and lasts for two days (featuring movies [1, 2]).

Write an efficient algorithm for the following assumptions:

    N is an integer within the range [1..100,000];
    each element of array A is an integer within the range [0..1,000,000,000].
*/