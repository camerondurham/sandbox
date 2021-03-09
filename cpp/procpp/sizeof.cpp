#include <iostream>
class c
{
	int i;
	char c;
	virtual void f() {}
};
int main()
{
	// why the fuck is this 12 on a raspberry pi?
	// makes sense it's 16 on a normal x86 processor
	std::cout << sizeof(c) << "\n";
}
