#include<stdio.h>
#define PRINT(X) printf("PRINT: %d", X);

int main(void){
	/*pointer t of integer type */
	int *p;

	int var = 10;

	p = &var;
	printf("Value of var is %d\n", var);
	printf("Address of var is: %u\n", &var);
	printf("Address of var is: %u\n", p);

	//print the address of pointer p
	printf("Address of p is: %u\n", &p);
	//another statement to print value of var
	printf("Value of var is: %d\n", *p);

    PRINT(var);

	getchar();
	return 0;
}
