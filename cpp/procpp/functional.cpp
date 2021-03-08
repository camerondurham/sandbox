#include<functional>
#include<numeric>
#include<vector>
#include<iostream>

using std::vector;
using std::cout;

int main(int argc, char** argv)
{
	vector<int> v({1, 2, 3, 4});
	vector<int> diff(v);
	int i = std::accumulate(v.begin(), v.end(), 0);
	std::adjacent_difference(diff.begin(),
			diff.end(),
			diff.begin());
	diff[0] = 0;
	for(int ii : diff)
	{
		cout << ii << ' ';
	}

	int j = std::accumulate(diff.begin(), diff.end(), 0);

	cout << '\n';
	cout << "size: " << v.size() << '\n';
	cout << "sum: " << i << '\n';
	cout << "adj_diff size: " << diff.size() << '\n';
	cout << "adj_diff sum: " << j << '\n';
}
