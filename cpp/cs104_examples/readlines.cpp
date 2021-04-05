/*
 * =====================================================================================
 *         Author:  Cameron Durham
 *        Program:  readlines.cpp
 *           Date:  08/21/2018
 *           Goal:
 *        Purpose:
 * =====================================================================================
 */

#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
using namespace std;

int main() {
   string word;
   stringstream buf;
   cin >> buf;
   int i = 1;


   while(!cin.fail()){
       i++;
      cout << word;
      cin >> word;

   }
   // print word count
   cout <<    i    << endl;
}
