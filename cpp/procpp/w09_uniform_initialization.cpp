#include <vector>
#include <utility>
#include <string>
#include <initializer_list>

struct Point {
	int x;
	int y;
	int z;
};

struct Test2 {
	Point topLeft;
	Point botRight;
};

int main(int argc, char** argv) {
	Test2 t2{
		{5, 10, 15}, // Top left
		{2, 4, 6}, // Bottom right
	};

	std::vector<int> v{ 2, 4, 6, 8, 10 };

	std::list<int> l{1, 3, 5, 7, 9 };
	
	std::pair<std::string, int> p{ "Hello", 6};
}
