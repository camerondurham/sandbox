/*
 * =====================================================================================
 *         Author:  Cameron Durham
 *        Program:  problem2.cpp
 *           Date:  05/25/2018
 *           Goal:  Print even Fibonacci numbers less than 4 million
 *        Purpose:
 * =====================================================================================
 */

#include<iostream>
int main() {
    unsigned int f1=0 ,f2=1 ,fnext=0, evensum;
    while( (f1 + f2) < 4000000){
        fnext = f1 + f2;
        if(fnext%2 == 0)
            evensum += fnext;
        f1 = f2;
        f2 = fnext;
    }
   
    std::cout << evensum;
    
    return 0;
}
