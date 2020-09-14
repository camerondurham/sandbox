#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

template <typename F>
void forEach(vector<int>& values, F&& func) {
	for (int& value : values)
		func(value);
}
void print(const vector<int>& values) {
	for(int value : values) {
		cout << value << " ";
	}
	cout << endl;
}
int main() {
	vector<int> values = {4, 8, 15, 16, 23, 42};
	cout << "BEFORE:" << endl;
	print(values);
	forEach(values, [](int& number) {number *= number;});
	cout << "AFTER:" << endl;
	print(values);
}
