#include <map>
#include <string>
using std::map;
using std::string;
struct Interval
{
  int start;
  int end;
};

map<string, string> LinearScan(map<string, Interval> &intervals,
                               int numInstr)
{
  map<string, bool> available = {
      {"ax", true},
      {"bx", true},
      {"cx", true},
      {"dx", true},
  };
  map<string, string> virtualToReal;
  for (size_t i = 0; i < numInstr; ++i)
  {
    for (const auto &interval : intervals)
    {
      if (interval.second.end == i)
      {
        std::string regAssignment = virtualToReal.at(interval.first);
        available.at(regAssignment) = true;
      }
    }

    for (const auto &interval : intervals)
    {
      if (interval.second.start == i)
      {
        bool assigned = false;
        for (const auto &it = available.begin(); it != available.end() && !assigned; ++it)
        {
          if (it->second)
          {
            virtualToReal.at(interval.first) = it->first;
            available.at(it->first) = false;
            assigned = true;
          }
        }
      }
    }
  }
  return virtualToReal;
}