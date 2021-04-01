#include <iostream>

int main()
{
	int result = 0;
	__asm
	{
		push 5
		push 6
		push 10
		pop ebx
		pop eax
		imul ebx
		push eax
		pop ebx
		pop eax
		add eax,ebx
		push eax
		push 7
		push 20
		pop ebx
		pop eax
		add eax,ebx
		push eax
		push 8
		pop ebx
		pop eax
		cdq
		idiv ebx
		push eax
		pop ebx
		pop eax
		sub eax,ebx
		push eax
		pop result
	}

	std::cout << "Result = " << result << std::endl;
}

