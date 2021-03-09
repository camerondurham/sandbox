# Practice Midterm Solutions

2.1

```cpp
struct Test {
 Test() { std::cout << "Default" << std::endl; }

 Test(const Test &rhs) { std::cout << "Copy" << std::endl; }

 Test &operator=(const Test &rhs) {
   std::cout << "Assignment" << std::endl;
   return *this;
 }

 Test(Test &&rhs) { std::cout << "Move" << std::endl; }

 Test &operator=(Test &&rhs) {
   std::cout << "Move Assignment" << std::endl;
   return *this;
 }

 ~Test() { std::cout << "Destructor" << std::endl; }
};

Test doStuff() {
 Test temp;
 return temp;
}

int main() {
 Test c = doStuff();
}
```

-------------

```cpp
Default // temp
Move // temp -> retval
Destructor // temp
Move // retval -> c
Destructor // retval
Destructor // c
```

### Notes

Why the move and not move assignment?

```cpp
Test c = doStuff(); // c hasn't been created yet

// this would be a move assignment
Test c;
c = doStuff();
```

2.2

Note: if you don’t implement the moves, then no moves occur!

* Will only create moves if you didn't create copy constructors
* Will autogenerate all copy and moves if you didn't make any default constructors


Code:

```cpp
struct Test {
 Test() { std::cout << "Default" << std::endl; }

 Test(const Test &rhs) { std::cout << "Copy" << std::endl; }

 Test &operator=(const Test &rhs) {
   std::cout << "Assignment" << std::endl;
   return *this;
 }

 ~Test() { std::cout << "Destructor" << std::endl; }
};

Test doStuff() {
 Test temp;
 return temp;
}

int main() {
 Test c = doStuff();
}
```

```cpp
Default // temp
Copy // temp -> retval
Destructor // temp
Copy // retval -> c
Destructor // retval
Destructor // c
```

3.1
Y doesn't compile because a++ doesn't return an l-value so you can't take the address of it

3.2
You can take the address of an l-value, but you can't of an r-value because it's a temporary
++a is an l-value
a++ is an r-value

3.3
If the object has only basic types, then the move and copy effectively do the same thing, so there's no performance gain.
OR
If the object passed in is an l-value, then it cannot use the move.

3.4
Because a was moved into b, a.DoStuff()'s behavior is undefined

4.1
4
```
(layout of Y)
vtable* // 8
char r | 3 padding | int i // 16
char s | 7 padding // 24
```
4.2
32

4.3

```
vtable* // 8
char r | 3 padding | int i // 16
char s | 7 padding // 24
double d
```

(vtable for Y)
```
[0] Y::b
[1] Y::~Y
```
4.4
```
[0] Z::b
[1] Z::~Z
[2] Z::w
```
5
```cpp
class Vector2 {
    float X, Y;
public:
    Vector2();
    ~Vector2();
    Vector2(const Vector2& other); // Copy constructor
    float GetX() const;
    float GetY() const;
    void SetX(float x);
    void SetY(float y);
    Vector2 operator+(const Vector2& other) const;
    friend bool operator==(const Vector3& lhs, const Vector3& rhs);
};
```
6.1
Any two of these:
* Use a switch of an if/else if/etc
* Use operator += instead of operator+
* Declare Str outside of the loop so it's not constructed on every iteration

6.2
If the string is below a "small" size which may be around 20 bytes, then it's possible to save the string in memory without using dynamic allocation, which makes it faster.

6.3
Inline functions don't have the overhead of actually calling a function because effectively the code is copy/pasted everywhere the inlined "function" is "called"

7.1

```
vector<double> result;
// Use default operator for adj_difference
std::adjacent_difference(input.begin(), input.end(),
 std::back_inserter(result));

// Because normally input.begin() is copied directly to index 0 of result
// We need to manually set to 0.0
result[0] = 0.0;
return result;
```
7.2
(the signature should return a vector of int, DailyResult pairs)

```
vector<pair<int, DailyResult>> result;

int day = -1;
std::transform(input.begin(), input.end(), std::back_inserter(result),
 [&day](double change) {
  day++;
  if (change == 0.0) { return std::make_pair(day, HOLD); }
  else if (change < 0.0) { return std::make_pair(day, SELL); }
  else { return std::make_pair(day, BUY); }
});
return result;
```

7.3

```
vector<pair<int, DailyResult>> part1;
std::copy_if(input.begin(), input.end(), std::back_inserter(part1),
 [](const pair<int, DailyResult>& p) {
  return p.second == SELL;
});

vector<int> result;
std::transform(part1.begin(), part1.end(), std::back_inserter(result),
 [](const pair<int, DailyResult>& p) {
  return p.first;
});
return result;
```

8

```
bool success = false;
std::ifstream::pos_type size;
char* memblock = nullptr;
std::ifstream file(fileName,
 std::ios::in|std::ios::binary|std::ios::ate);
if (file.is_open())
{
 size = file.tellg();
 memblock = new char[static_cast<size_t>(size)];
 file.seekg(0, std::ios::beg);
 file.read(memblock, size);
 file.close();
 if (memblock[0] == 'I' && memblock[1] == 'T' &&
  memblock[2] == 'P' && memblock[3] == 'W')
 {
  success = true;
  SampleRate = *(reinterpret_cast<unsigned int*>(&memblock[4]));
  NumChunks = *(reinterpret_cast<unsigned int*>(&memblock[8]));
  for (unsigned int i = 0; i < NumChunks; i++)
  {
   size_t startAddr = 12 + i * sizeof(Chunk);
   Chunk chunk;
   chunk.ID = *(reinterpret_cast<unsigned int*>
       (&memblock[startAddr]));
   std::memcpy(chunk.Samples, memblock + startAddr + 4, 1024);
   Chunks.emplace_back(chunk);
  }
 }
 delete[] memblock;
}
return success;
```

9.1

```cpp
Vector::~Vector()
{
 delete[] mArray;
 // Technically not required, but you should do it
 mArray = nullptr;
 mSize = 0;
 mCapacity = 0;
}
```

9.2

```cpp
Vector::Vector(const Vector& rhs)
:mArray(new T[rhs.mCapacity])
,mSize(rhs.mSize)
,mCapacity(rhs.mCapacity)
{
 // Deep copy
 for (size_t i = 0; i < rhs.mSize; i++)
 {
  mArray[i] = rhs.mArray[i];
 }
}
```


9.3

```cpp
Vector::Vector(Vector&& rhs)
:mArray(std::move(rhs.mArray)) // shallow copy!!
,mSize(std::move(rhs.mSize))
,mCapacity(std::move(rhs.mCapacity))
{
 rhs.mArray = nullptr;
 rhs.mSize = 0;
 rhs.mCapacity = 0;
}
```


9.4

```cpp
Vector& Vector::operator=(const Vector& rhs)
{
 // Check for self-assignment
 if (this != &rhs)
 {
  // Clear already allocated memory
  delete[] mArray;
  // Deep copy of rhs
  mArray = new T[rhs.mCapacity];
  mSize = rhs.mSize;
  mCapacity = rhs.mCapacity;
  for (size_t i = 0; i < rhs.mSize; i++)
  {
   mArray[i] = rhs.mArray[i];
  }
 }
 // Always return *this
 return *this;
}

// Move assignment
Vector& Vector::operator=(Vector&& rhs)
{
 // Check for self-assignment
 if (this != &rhs)
 {
  // Clear already allocated memory
  delete[] mArray;
  // Shallow copy
  mArray = rhs.mArray;
  mSize = rhs.mSize;
  mCapacity = rhs.mCapacity;
  // Set rhs to nulled out
  rhs.mArray = nullptr;
  rhs.mSize = 0;
  rhs.mCapacity = 0;
 }
 // Always return *this
 return *this;
}
```

10.

```cpp
std::vector<char> v;
// This uses a trick to cast 2x chars to a short
// You didn't have to do it this way (most people used std::string)
short prev = *reinterpret_cast<const short*>(&input[0]);
char runSize = 1;
for (size_t i = 2; i < inSize; i += 2)
{
 short next = *reinterpret_cast<const short*>(&input[i]);
 if (prev == next && runSize < 127)
 {
  runSize++;
 }
 else
 {
  v.push_back(runSize);
  char* toWrite = reinterpret_cast<char*>(&prev);
  v.push_back(toWrite[0]);
  v.push_back(toWrite[1]);
  runSize = 1;
 }
 prev = next;
}

// Need to do final write
v.push_back(runSize);
char* toWrite = reinterpret_cast<char*>(&prev);
v.push_back(toWrite[0]);
v.push_back(toWrite[1]);
return v;
```


----------------------


## Move Notes


```cpp
Test doStuff() {
  Test temp;
  temp.mName = "Hello World!";
  return temp; // this moves form temp to a hidden retval
}
int main() {
  Test a(doStuff()); // this moves from the hidden retval to `a`
  std::cout << a.mName << std::endl;
  return 0;
}
```


When do move semantics do you no good?

* No move operations: The object to be moved from fails to offer move
  operations. The move request therefore becomes a copy request.
* Move not faster: The object to be moved from has move operations that are no
  faster than its copy operations.
* Move not usable: The context in which the moving would take place requires a
  move operation that emits no exceptions, but that operation isn’t declared
  noexcept.
* Source object is an `lvalue`, with a few exceptions


### xvalue and `std::move`

`std::move` returns an xvalue. An `xvalue` is an expression that identifies an
**eXpiring** object that can be moved from. Conceptually, you can think of an xvalue
as a subset of rvalue.

## Optimization Notes

### Loop Unrolling

Reduce number of iterations to reduce conditional checks/increment ops
if **code inside loop is smaller than this overhead.**

**Bonus:** When doing numerical computations as the previous
example, the unrolled loop is more likely to be identified as a
candidate for vectorization (SIMD)

```cpp
// Sum array of 1000 elements
float sum = 0.0f;
for (int i = 0; i < 1000; i++)
{
  sum += myArray[i];
}

// Sum array of 1000 elements
float sum = 0.0f;
for (int i = 0; i < 1000; i+=4)
{
  sum += myArray[i] + myArray[i + 1] +
        myArray[i + 2] + myArray[i + 3];
}
```

## Rule of Five

If you're compelled to implement any of the following, implement all of these:

* Destructor
* Copy Constructor
* Assignment Operator
* Move Constructor
* Move Assignment Operator


**Rule of zero** in modern c++ says you shouldn't have to overload any of the five member functions!

Avoid using `new` altogether and instead use
* STL collections
* Smart pointers

### String Example

#### const char\* constructor

```cpp

 // Construct from const char*
 string(const char* str)
  :mSize(std::strlen(str))
  ,mCapacity(mSize < 20 ? 20 : mSize + 1)
  ,mData(new char[mCapacity])
 {
  memcpy(mData, str, mSize + 1);
 }

```

#### copy constructor


```cpp
 // Copy constructor
 string(const string& rhs)
  :mSize(rhs.mSize)
  ,mCapacity(rhs.mCapacity)
  ,mData(new char[mCapacity])
 {
  memcpy(mData, rhs.mData, mSize + 1);
 }
```

#### assignment operator

```cpp
 // Assignment operator
 string& operator=(const string& rhs)
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
```

#### destructor


```cpp
 // Destructor
 ~string()
 {
  delete[] mData;
  mSize = 0;
  mCapacity = 0;
 }
```

#### move constructor

```cpp
 string(string&& rhs) noexcept
  :mSize(std::move(rhs.mSize))
  ,mCapacity(std::move(rhs.mCapacity))
  ,mData(std::move(rhs.mData))
 {
  // Set rhs data to null so not deleted from under us
  rhs.mData = nullptr;
  rhs.mSize = 0;
  rhs.mCapacity = 0;
 }
```

#### move assignment operator

```cpp

 // Move Assignment operator
 string& operator=(string&& rhs) noexcept
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
```
#### plus equals operator (not R5)

```cpp

 string& operator+=(const string& rhs)
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

```

#### plus operator

```cpp

 friend string operator+(const string& lhs, const string& rhs)
 {
  string temp(lhs);
  temp += rhs;
  return temp; // this is an expiring value
 }
};
```


## Functional Programming

