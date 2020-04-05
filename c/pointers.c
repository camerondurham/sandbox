#include<stdio.h>
int main(){
    int *p,x=5;
    p=&x;
    x=++*p;
    printf("%d, %p\n",x,p);
    x=*p++;
    printf("%d, %p\n",x,p);
    x=++*p;
    printf("%d, %p\n",x,p);
    // printed -399375703
}
