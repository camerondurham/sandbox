// how big are certain things in c?

#include <stdio.h>

int main(int argc, char *argv[])
{
	int i;
	double j;
	float k;
	char l;
	char ll[10];
	int ii[10];

	printf("An integer is %d bytes\n",sizeof(i));
	printf("A double is %d bytes\n",sizeof(j));
	printf("An float is %d bytes\n",sizeof(k));
	printf("An char is %d bytes\n",sizeof(l));

	// how big is an array?
	printf("An array of 10 characters is %d bytes\n",
		    sizeof(ll));

	printf("An array of 10 integers is %d bytes\n",
		    sizeof(ii));



	return 0;
}
