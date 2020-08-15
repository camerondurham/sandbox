#include <cstdio> // or <cstdio>
using namespace std;

char digits[100];//using global variables in contests can be a good strategy

int main(){
    int N = 0;
    scanf("%d", &N);
    
    while(N--){ //we simply loop from N, N-1, ..., 0
        char c;
        while((c=getchar()) != '\n');
        scanf("0.%[0-9]...", &digits);
        printf("the digits are 0.%s\n", digits);
    }   }

