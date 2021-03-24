#include <iostream>
#include<vector>
#include<unordered_set>
#include<unordered_map>
using namespace std;


int solution(vector<int> A){
  unordered_map<int,int> um;
  for(int a : A)
   um[a]++;
  
  for(int i = 0; i < 3; ++i)
  {
    int minCount = 51;
    int integer = 0;
    for(auto it = um.begin(); it != um.end(); ++it)
    {
      if(it->second < minCount)
      {
        minCount = it->second;
        integer = it->first;
      }
    }
    if(um[integer] == 1)
    {
      um.erase(um.find(integer));
    }
    else
    {
      um[integer] -= 1;
    }
  }


  cerr << "Tip: Use cerr to write debug messages on the output tab.";
  return  um.size(); 
}

/*
 [11, -2, -1, 11, -2, -1], 2
 [-2, -1, -1, -1, -2, -1]
 
 [10, 9, 2, 2, -3], 1
 [2 , 2, 2, 2,  2]

 
*/

/*
We are given an array A consisting of N integers. In one move, we can choose any element in this array and replace it with any value.

What is the minimum number of distinct values in the array that we can achieve by performing at most three moves?

Write a function:

class Solution { public int solution(int[] A); }

that, given an array A of N integers, returns the minimum number of distinct values that can be obtained after replacing up to three elements of array A.

Examples:

    Given A = [-9, 8], the function should return 1. We can replace -9 with 8 and then 8 will be the only distinct value.
    Given A = [1, 1, 1, 1, 1], the function should return 1. There is nothing that we can do to reduce the number of distinct values.
    Given A = [11, -2, -1, 11, -2, -1], the function should return 2. We can for example replace both values 11 with -1 and -2, which leaves us with two different values.
    Given A = [10, 9, 2, 2, -3], the function should return 1. We can replace 10, 9 and -3 with 2 such that all values are equal to 2.

Assume that:

    N is an integer within the range [1..12];
    each element of array A is an integer within the range [−50..50].

In your solution, focus on correctness. The performance of your solution will not be the focus of the assessment.
*/