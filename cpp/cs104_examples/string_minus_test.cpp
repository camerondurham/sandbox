#include <iostream>
#include <string>
using namespace std;

//prototype
string operator-(string, const string &);

int main()
{
	    //cout << "Hello World" - "He" << endl;
	char b = -6;
	short a = b;
	int x = b;

	printf("char=%hhi    int =%x   short=%x", b, x, a );
	//cout << "Testing \n" << x << "\n";


}

string operator-(string firstOp, const string &secondOp)
{
	    //test if the firstOp contains the secondOp
	    if (firstOp.find(secondOp) != string::npos)
		        {
				        //erase the secondOp of the firstOp
				        firstOp.erase(firstOp.find(secondOp), secondOp.length());
					    }
	        return firstOp;
}
