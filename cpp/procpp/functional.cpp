#include <algorithm>
#include <functional>
#include <numeric>
#include <vector>
#include <iostream>

using std::cout;
using std::vector;

std::vector<float> divEachBy(const std::vector<float> &v,
                             float denominator)
{
  std::vector<float> ret;
  // std::transform can be used to map
  std::transform(v.begin(),								// Start of range
                 v.end(),									// End of range
                 std::back_inserter(ret), // Collection to insert into
                 // Unary Function that returns transform value
                 [denominator](const float &a) {
                   return a / denominator;
                 });
  return ret;
}

int main(int argc, char **argv)
{
  vector<int> v({1, 2, 3, 4});
  vector<int> diff(v);
  int i = std::accumulate(v.begin(), v.end(), 0);
  std::adjacent_difference(diff.begin(),
                           diff.end(),
                           diff.begin());
  diff[0] = 0;
  for (int ii : diff)
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
