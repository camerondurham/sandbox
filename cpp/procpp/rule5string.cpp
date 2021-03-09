#include <cstring>
#include <utility>
#include <iostream>

class string
{
  size_t mSize;
  size_t mCapacity;
  char *mData;

public:
  // Construct from const char*
  string(const char *str)
      : mSize(std::strlen(str)), mCapacity(mSize < 20 ? 20 : mSize + 1), mData(new char[mCapacity])
  {
    memcpy(mData, str, mSize + 1);
  }

  // Copy constructor
  string(const string &rhs)
      : mSize(rhs.mSize), mCapacity(rhs.mCapacity), mData(new char[mCapacity])
  {
    memcpy(mData, rhs.mData, mSize + 1);
  }

  // Assignment operator
  string &operator=(const string &rhs)
  {
    // Don't do anything for self-assignment
    if (this != &rhs)
    {
      // Delete existing dynamically allocated data
      delete[] mData;

      // Deep copy
      mSize = rhs.mSize;
      mCapacity = rhs.mCapacity;
      mData = new char[mCapacity];
      memcpy(mData, rhs.mData, mSize + 1);
    }
    // Always return *this
    return *this;
  }

  // Destructor
  ~string()
  {
    delete[] mData;
    mSize = 0;
    mCapacity = 0;
  }

  // Move Constructor
  string(string &&rhs) noexcept
      : mSize(std::move(rhs.mSize)), mCapacity(std::move(rhs.mCapacity)), mData(std::move(rhs.mData))
  {
    // Set rhs data to null so not deleted from under us
    rhs.mData = nullptr;
    rhs.mSize = 0;
    rhs.mCapacity = 0;
  }

  // Move Assignment operator
  string &operator=(string &&rhs) noexcept
  {
    // Don't do anything for self-assignment
    if (this != &rhs)
    {
      // Delete existing dynamically allocated data
      delete[] mData;

      // Shallow copy
      mSize = std::move(rhs.mSize);
      mCapacity = std::move(rhs.mCapacity);
      mData = std::move(rhs.mData);

      // Set rhs data to null so not deleted from under us
      rhs.mData = nullptr;
      rhs.mSize = 0;
      rhs.mCapacity = 0;
    }
    // Always return *this
    return *this;
  }

  string &operator+=(const string &rhs)
  {
    // Check if there's enough space and if not, grow
    // (omitted)
    // ...

    for (size_t i = 0; i < rhs.mSize + 1; i++)
    {
      mData[mSize + i] = rhs.mData[i];
    }
    mSize += rhs.mSize;
    return *this;
  }

  friend string operator+(const string &lhs, const string &rhs)
  {
    string temp(lhs);
    temp += rhs;
    return temp; // this is an expiring value
  }
};

int main(int argc, char **argv)
{
  string x("abc");
  string y("def");
  x += y;           // first runs operator+ then copy constructor
  string z = x + y; // operator+ then copy constructor, then destructor happens from operator +

  // string z;
  // z = x + y; would be assignment, but the prev line is copy constructor
}