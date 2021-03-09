#include <algorithm>
#include <functional>
#include <numeric>
#include <vector>
#include <iostream>
#include <unordered_set>

using std::cout;
using std::vector;

// map or transform example
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

float sumVector(const std::vector<float>& v) {
  // std::accumulate works as a REDUCE
  return std::accumulate(v.begin(),
  v.end(),
  0.0f, // initial value
  // binary lambda expression
  [](const float& a, const float& b) {
    return a + b;
  });
}

// copy_n example

std::vector<int> CombinePaths(const std::vector<int>& begin, const std::vector<int>& end, int crossoverIndex, int nLoc)
{
    std::vector<int> child;
    child.reserve(nLoc);

    std::copy_n(begin.begin(), crossoverIndex + 1, std::back_inserter(child));
    std::unordered_set<int> s(child.begin(), child.end());
    child.resize(nLoc);
    std::copy_if(end.begin(), end.end(), child.begin() + crossoverIndex + 1, [&s](int i){
        return s.find(i) == s.end();
    });

    return child;
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

  // all_of example
  std::vector<int> v1{2, 4, 6, 8, 10};
  if (std::all_of(v1.begin(), v1.end(), [](const int &i) {
        return (i % 2) == 0;
      }))
  {
    std::cout << "All are even!" << std::endl;
  }
  else
  {
    std::cout << "All aren't even" << std::endl;
  }

  // copy_if example
  std::vector<int> from{1, 2, 3, 4, 5};

  std::vector<int> to;

  auto is_odd = [](const int &i) { return i % 2 == 1 };

  // Copy from the "from" container into the "to" container,
  // only if is_odd returns true for that element
  std::copy_if(from.begin(), from.end(),
               std::back_inserter(to), is_odd);

  // generate example to insert elements into a collection
  // where elements need to be initialized by a particular function
  std::vector<int> filler(10);
  std::generate(v.begin(),
  v.end(),
  [](){
    return rand();
  });

  from = {10, 15, 20, 25, 30, 35};
  to.clear();
  std::adjacent_difference(from.begin(),
  from.end(),
  std::back_inserter(to),
  [](int a, int b){
    return a - b;
  });

  // first element in resulting range is a copy, rest of collection is differences
  // to will contain: {10, 5, 5, 5, 5, 5}
}
