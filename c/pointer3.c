#include<stdio.h>
#include<stdlib.h>

/* Write a prog that: 1.) declares "q" and assigns it to val of 50; 2.) create pointer to q; 3.) display q's value using the pointer to variable. */

int main(void){

	int *p, q;
	q = 50; 
	p = &q; //address of q assigned to p

	//displays q's value using p variable
	printf("Value of q: %i\n", *p); 
	printf("%d\n", p);
	printf("%u\n", *p);
	printf("%d\n", *&q);


	return 0;
}
