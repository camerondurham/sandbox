#include<vector>
using namespace std;

// from coding interview in C++ array boot camp

void EvenOdd(vector<int>* A_ptr)
{
  vector<int>& A = *A_ptr;
  int next_even = 0, next_odd = A.size() - 1;
  while(next_even < next_odd)
  {
    if(A[next_even] % 2 == 0)
      ++next_even;
    else
      swap(A[next_even], A[next_odd--]);
  }
}
