#include <stdio.h>
// scanf returns the number of properly parsed values
int main()
{
    float f;
    int rv0 = scanf("%f", &f);
    char c;
    int rv1 = scanf("%c", &c);
    printf("\n\n: rv0: %d, rv1: %d\n", rv0, rv1);
}
