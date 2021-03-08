#include<iostream>
class c {
	int i;
	char c;
	virtual void f(){}
};
int main()
{
	// why the fuck is this 12
	std::cout << sizeof(c) << "\n";
}
