#include <cstdio>
#include <utility>
#include <ctype.h>
#include <vector>
#include <iostream>
#include <type_traits>
#include <algorithm>

using std::cout;

void LoopOnVector(const std::vector<int>& v)
{
	v.size();
	for (int i : v)
	{
		cout << i;
	}
}

int main(int argc, char** argv)
{
	int* p = nullptr;
	std::vector<int> localv(500000);
	LoopOnVector(localv);
	LoopOnVector(std::vector<int>(50));

	LoopOnVector({50, 100, 70, 85, 90});
	return 0;
}