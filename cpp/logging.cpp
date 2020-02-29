// source https://codingbyexample.com/2019/01/11/preprocessor-macros-c-features/
// compile with:
//    gcc -DVERBOSE_LEVEL=1 sample2.cpp -o sample2V1


#include <stdio.h>      // printf

#define PI 3.14159265359

int main()
{
// Using a defined macro that has a definition set
#ifdef VERBOSE_LEVEL
#if VERBOSE_LEVEL == 1
    printf("Currently running with verbose level %d\n", VERBOSE_LEVEL);
    printf("PI is %lf\n", PI);
#endif
#if VERBOSE_LEVEL == 2
    printf("Currently running with verbose level %d\n", VERBOSE_LEVEL);
    printf("PI is %lf\n", PI);
    printf("More Text\n");
#endif
#else
    printf("bye\n");
#endif

    return 0;
}
