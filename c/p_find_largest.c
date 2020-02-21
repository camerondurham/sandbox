#include<stdio.h>
#define size 10
int a[size]={20,2,23,[9]=1}; //Largest == 23
int b[size]={2,1,10,[9]=1}; //Largest == 10

int *find_largest(int a[],int n);
int *p, *q;
int main(void)
{
	p = find_largest(a,size);
	q = find_largest(b,size);
	printf("Largest size in array a: %d\n", *p);
	printf("Largest size in array b: %d\n", *q);
	getchar();
	return 0;
}


int *find_largest(int a[],int n)
{int max, i;
	for(max=0,i=1;i<n;i++){
		if(a[i]>a[max]) max = i;}
	return &a[max];
}
