#include	<stdio.h>

const N=8;

int arrivals_hr[8] = {10,11,13,15,16,17,21,23};
int arrivals_mm[8] = {16,52,31, 0, 8,55,20,58};
int i=0,mins=0;
int main(void)
{
	printf("Hours past midnight of arrival times\n");
	for ( i=0 ;i<N ;i++ ) {
		mins = arrivals_hr[i] * 60 + arrivals_mm[i] ;
		printf("#%i.\t%5i\n", i+1, mins);
			
	}
	return 0;
}
