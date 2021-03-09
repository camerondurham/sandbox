#include<fstream>
#include<vector>
#include<functional>
#include<algorithm>
#include<numeric>
using std::vector;
vector<float> CalculateSMA(const vector<float>& prices, unsigned int period) {
  vector<float> retval(prices.size());
  float avgsum(0.0f);
  unsigned int index(0);
  std::generate(retval.begin(), retval.end(), [&avgsum, &index, period, prices](){
    if(index - period > 0) avgsum -= prices[index-period];
    avgsum += prices[index];
    index++;
    if(index < period){
      return 0.0f;
    } else {
      return avgsum / period;
    }
  });
  return retval;
}

vector<int> CompareWithSMA(const vector<float> &prices,
                           const vector<float> &sma)
{
  vector<int> retval(prices.size());
  unsigned int index(0);
  std::generate(retval.begin(), retval.end(), [&index, prices, sma](){
    int ret(0);
    if(prices[index] == sma[index])
      ret = 0;
    else if (prices[index] > sma[index])
      ret = +1;
    else
      ret = -1;

    index++;
    return ret;
  });
  return retval;
}


void CreateArchive(const std::vector<std::string>& fileNames) {
  char sig[5] = {'R', 'Z', 'I', 'P', '\x01'};

  std::string filename("out.rzip");
  size_t sz = fileNames.size();
	std::ofstream arc(filename, std::ios::out | std::ios::binary | std::ios::trunc);
	if (arc.is_open())
  {
    arc.write(sig, 5);
    arc.write(reinterpret_cast<char*>(&(sz), 8), 8);

    std::ifstream::pos_type size;
    char *memblock;
    for (const auto &f : fileNames)
    {

      std::ifstream file(f, std::ios::in | std::ios::binary | std::ios::ate);
      if (file.is_open())
      {
        size = file.tellg();
        memblock = new char[static_cast<unsigned int>(size)];
        RleData data = GetRleData(memblock, size);
        uint32_t crc = GetCRC(data);

        size_t nameLen = f.size();
        arc.write(reinterpret_cast<char*>(&(size)), 8);
        arc.write(reinterpret_cast<char*>(&(data.mSize)), 8);
        arc.write(reinterpret_cast<char*>(&(nameLen)), 8);
        arc.write(reinterpret_cast<char*>(&(crc)), 4);
        arc.write(f.c_str(), f.size());
        arc.write(data.mData, data.mSize);

        delete[] memblock;
        file.close();
      }
    }
    arc.close();
  }

}

LinkedList &LinkedList::operator=(const LinkedList &&rhs)
{
  if (this != &rhs)
  {
    Node *tmp = head;
    while (tmp != nullptr)
    {
      Node *old = tmp;
      tmp = tmp->next;
      delete old;
    }

    head = std::move(rhs.head);
    rhs.head = nullptr;
  }
  return *this;
}

template <typename ValueType, typename PrimaryHashT, typename SecondaryHashT>
class HashTable {
   // Functions declarations excluded for brevity...
   std::pair<std::string, ValueType>* mTableData; // Underlying array
   size_t mCapacity;           // Max elements
   size_t mSize;               // Current number of elements
   PrimaryHashT m1stHash;   // Primary hashing function
   SecondaryHashT m2ndHash; // Secondary hashing function
};



/*
pH = primaryHash(key)
sH = secondaryHash(key)

0th: (pH + 0 * sH) % capacity
1st: (pH + 1 * sH) % capacity
2nd: (pH + 2 * sH) % capacity
3rd: (pH + 3 * sH) % capacity
...
*/

template <typename ValueType, typename PrimaryHashT, typename SecondaryHashT>
ValueType* HashTable::Find(const std::string& key) const {
  size_t pH = m1stHash(key);
  size_t sH = m2ndHash(key);
  size_t index = 0;
  while(index <= 10)
  {
    size_t tryIdx = (pH + index * sH) % mCapacity;
    if(mTableData[tryIdx].first.empty())
    {
      return nullptr;
    }
    if(mTableData[tryIdx].first == key)
    {
      return &(mTableData[tryIdx].second);
    }
    index++;
  }
  return nullptr;
}