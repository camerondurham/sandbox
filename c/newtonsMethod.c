/*
 * =====================================================================================
 *
 *       Filename:  newtonsMethod.c
 *
 *    Description:  Uses Newton's Method to compute roots
 *
 *        Version:  1.0
 *        Created:  08/08/2017 08:46:04 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Cameron Durham (CD), msu-cdurham@student.mcneese.edu
 *        Company:  
 *
 * =====================================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define EPSILON 0.00001
#define N0 30
double f(double x);
double fprime(double x);
double newtonsMethod(double p0arg);
double bisectionMethod(double p0, double p1);


double p0[] = { -10, -5, -3,
		-1,   0,  1,
		3,    5, 10};

double p1 = 0.0, pn = 0.0, answer = 0.0;
int n = 1, i = 0;

int main(void) {
	
	while(i < 9) {
		printf("\n-----------------Initial Point = %.0lf-----------------------\n", p0[i]);
		printf("\n\tp = %.10lf\n", newtonsMethod(p0[i]) );
		i++;
	}

	return 0;
}

double f(double x)
{
	return (4*x*x - exp(x) - exp(-x));
}

double fprime(double x)
{
	return (8*x - exp(x) + exp(-x));
}

double newtonsMethod(double p0arg)
{
	int i=0; 
	double p0 = p0arg;
	double p = 0, fValue = 0, fPrime = 0;

	while(i<N0) {
		if( (fPrime = fprime(p0) )==0) {
			printf("Error: Div/0\n");
			return 0;
		}
		fValue = f(p0);
		p = p0 - (fValue / fPrime);
		
		printf("p%d  =  %.10lf  f(p) = %.10lf\n", i, p, f(p));
		if( ((fValue = f(p)) < 0 && -fValue < EPSILON) || ( (fValue > 0) && fValue < EPSILON)  ) {
			printf("Found: error = %.10lf	p%d\n", fValue, i);
			return p;
		}
		i++;
		p0 = p;

	}

}

double bisectionMethod(double p_0, double p_1)
{
	int i = 0;
	double p0 = p_0, p1 = p_1, pn = 0, f_p0 = f(p_0), f_p1 = f(p_1), f_pn = 0;
	
	bracketingTest(p0,p1);
	
	while(i < N0) {
		pn = midpoint(p0,p1);
		f_pn = f(pn);

	}
}

int bracketingTest(double p0, double p1)
{
	double f_p0 = f(p0), f_p1 = f(p1);

	if(f_p0 < 0 && f_p1 > 0)
		return 1;
	else if(f_p0 > 0 && f_p1 < 0)
		return 1;
	else
	{
		printf("Points do not bracket a zero\n");
		return 0;
	}

}

double midpoint(double p0, double p1)
{
	double mid = 0;
	
	return p0 + (p1 - p0)/2;
}

/*
int signum(double p)
{
	double x = f(p);

	if(x > 0)
		return 1;
	else if(x < 0)
		return -1;
	else
		return 0;
}
*/
