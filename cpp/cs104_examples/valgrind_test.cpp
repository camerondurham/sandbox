#include<stdio.h>
int main()
{
  int j;
  int* arr = new int[2]; // ==112== 8 bytes in 1 blocks are definitely lost in loss record 1 of 6

  int ** matrix = new int*[2];
  matrix[0] = new int[2];

  j += arr[2]; // Invalid read of size 4

  if ( j == 66 ) // Conditional jump or move depends on uninitialised value(s)
    printf("hello there!\n");

  delete [] matrix;

  matrix[1][0] = 2;

  return 0;
}
