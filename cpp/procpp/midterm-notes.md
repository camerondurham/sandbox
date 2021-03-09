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

---

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

- Will only create moves if you didn't create copy constructors
- Will autogenerate all copy and moves if you didn't make any default constructors

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

no "default" constructor for structs?
no, dumb point bc constructors can't be virtual.

```
[0] Y::b
[1] Y::~Y
```

4.4

After adding (in order) any modifications from parent's class,
add new virtual functions from child class.

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

- Use a switch of an if/else if/etc
- Use operator += instead of operator+
- Declare Str outside of the loop so it's not constructed on every iteration

6.2
If the string is below a "small" size which may be around 20 bytes, then it's possible to save the string in memory without using dynamic allocation, which makes it faster.

6.3
Inline functions don't have the overhead of actually calling a function because effectively the code is copy/pasted everywhere the inlined "function" is "called"

7.1

```cpp
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

```cpp
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

```cpp
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

```cpp
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
   chunk.ID = *(reinterpret_cast<unsigned int*>(&memblock[startAddr]));
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

---

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

- No move operations: The object to be moved from fails to offer move
  operations. The move request therefore becomes a copy request.
- Move not faster: The object to be moved from has move operations that are no
  faster than its copy operations.
- Move not usable: The context in which the moving would take place requires a
  move operation that emits no exceptions, but that operation isn’t declared
  noexcept.
- Source object is an `lvalue`, with a few exceptions

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

### Sanjay Split

Don't trust Stack Overflow and don't use `std::stringstream`!

```cpp
std::vector<std::string> SplitSanjay(const std::string& str) {
  const char delim = ',';
  std::vector<std::string> retVal;
  size_t start = 0;
  size_t delimLoc = str.find_first_of(delim, start);
  while (delimLoc != std::string::npos) {
    retVal.emplace_back(str.substr(start, delimLoc - start));
    start = delimLoc + 1;
    delimLoc = str.find_first_of(delim, start);
  }
  retVal.emplace_back(str.substr(start));
  return retVal;
}
```

## Rule of Five

If you're compelled to implement any of the following, implement all of these:

- Destructor
- Copy Constructor
- Assignment Operator
- Move Constructor
- Move Assignment Operator

**Rule of zero** in modern c++ says you shouldn't have to overload any of the five member functions!

Avoid using `new` altogether and instead use

- STL collections
- Smart pointers

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


### Lambda Expression Syntax

```cpp
// [] <- capture clause
// () <- function parameters
// -> <- return value (optional)
// { ... } <- body
[&count](int i) -> int
{
  std::cout << i << std::endl;
  count++;
  return count;
}
```

Capture clause:

```cpp
// Capture ALL local variables by value (not recommended)
[=]

// Capture ALL local variables by reference (not recommended)
[&]

// Capture x by value and y by reference
[x, &y]

// Capture count by reference, and all other locals by value
[=, &count]

// Capture this by value (can't be captured by reference)
// If you want to use any member functions or variables in the
// lambda, you have to capture this.
[this]
```

Specifying the type of a lambda with `std::function` template in `<functional>` header:

```cpp
std::function<bool(int,int)> greater =
  [](int a, int b) {
    return a > b;
  };
```

### Functional Programming Paradigm

* in functional programming, functions are first-class citizens
* functions can
  * be passed as args to other functions
  * can be returned from other functions
  * can be assigned to a variable or stored in a container

* higher order functions (functions that can accept other functions as args) are allowed
* common higher order functions
  * `map` - apply a function to each element in the collection, storing result in another collection
  * `filter` - remove elements from a collection based on a filtering function
  * `reduce` - reduce a collection to a single value by applying a binary operation repeatedly
* function programming tries to limit **side effects** (having any interaction with the world "outside" from the instance function call)


**Reduce example**

Take a collection and reduce it to a single value by applying a binary operator repeatedly.

Reduce collection to the sum of its components.

Example:

```cpp
#include<numeric>
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
```

**all_of** example

```cpp
std::vector<int> v1{ 2, 4, 6, 8, 10 };
if (std::all_of(v1.begin(), v1.end(), [](const int& i) {
  return (i % 2) == 0;
}))
{
  std::cout << "All are even!" << std::endl;
}
else
{
  std::cout << "All aren't even" << std::endl;
}
```
**copy_n** example

* copies n elements from a source collection into a back_inserted collection

**copy_if** another example

```cpp
std::vector<int> from{ 1, 2, 3, 4, 5 };

std::vector<int> to;

auto is_odd = [](const int& i) { return i % 2 == 1 };

// Copy from the "from" container into the "to" container,
// only if is_odd returns true for that element
std::copy_if(from.begin(), from.end(),
  std::back_inserter(to), is_odd);
```

**map** example (C++ `std::transform`)

* map higher order function applies a function to each element and saves results in a different collection

```cpp

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
```


**generate** example


```cpp
std::vector<std::pair<int,int>> GeneratePairs(std::mt19937& generator, const std::vector<double>& probabilities)
{
    std::vector<std::pair<int,int>> ret(probabilities.size());
    std::generate(ret.begin(), ret.end(), [&probabilities, &generator](){
        std::uniform_real_distribution<double> dist;
        double randomA = dist(generator);
        double randomB = dist(generator);
        int parentA = SelectParent(probabilities, randomA);
        int parentB = SelectParent(probabilities, randomB);
        return std::make_pair(parentA, parentB);
    });
    return ret;
}

```

## Parallel Examples

`tbb::parallel_for`

```cpp
std::vector<std::string> v; // Assume has stuff
tbb::parallel_for(tbb::blocked_range<size_t>(0, v.size()),
    [&v](const tbb::blocked_range<size_t>& r) {
    // Make temporary once per range :)
    std::string tempStr;
    // Iterate over range
    for (size_t i = r.begin(); i != r.end(); ++i) {
      // Do somethign with v[i]
    }
});
```

`tbb::parallel_invoke`

```cpp
tbb::parallel_invoke(
  [this] { BruteForceHelper(unsolvedPass, 0, 3); },
  [this] { BruteForceHelper(unsolvedPass, 4, 7); },
  [this] { BruteForceHelper(unsolvedPass, 8, 11); },
  [this] { BruteForceHelper(unsolvedPass, 12, 15); },
  [this] { BruteForceHelper(unsolvedPass, 16, 19); },
  [this] { BruteForceHelper(unsolvedPass, 20, 23); },
  [this] { BruteForceHelper(unsolvedPass, 24, 27); },
  [this] { BruteForceHelper(unsolvedPass, 28, 31); },
  [this] { BruteForceHelper(unsolvedPass, 32, 35); }
);
```


### STL Collections for Parallel Programming

* assume adding/removing elements from an STL collection **is unsafe in a parallel operator**
* reading specific elements as long as nobody is adding/removing should be ok
* writing to specific elements **may** be okay but depends how it's being done

## Smart Pointers

`std::unique_ptr`

* A pointer that allows only a single reference at a time
* uniquely controls object's lifetime
* when pointer goes out of scope, object is deleted
* create with `std::make_unique`


`std::shared_ptr`

* Allows multiple references at once
* used when an object has shared ownership between multiple pointers
* uses **reference counting** to track number of references there are to the dynamically allocated object
* automatically deallocated when ref count == 0
* create with `std::make_shared`


`std::weak_ptr`

* Allows for weak references to shared pointers
* allows a pointer to keep a weak reference to a shared pointer
* a **weak reference** does NOT affect the lifetime of the object because if uses a separate count
* used to peek at the lifetime of an object (if expired or not)


## Writing to Binary Files


```cpp
void RleFile::CreateArchive(const std::string& source)
{
	// TODO
	std::ifstream::pos_type size;
	char* memblock;
	// Open the file for input, in binary mode, and start ATE (at the end)
	std::ifstream file(source, std::ios::in | std::ios::binary | std::ios::ate);
	if (file.is_open())
	{
		size = file.tellg(); // Save the size of the file
		memblock = new char[static_cast<unsigned int>(size)];
		file.seekg(0, std::ios::beg); // Seek back to start of file
		file.read(memblock, size);
		file.close();
		// File data is now in memblock array

		mRleData.Compress(memblock, static_cast<unsigned int>(size));

		delete[] memblock;
	}

	std::string filename(source + ".rl1");

	// Open the file for output, in binary mode, and overwrite an existing file
	std::ofstream arc(filename, std::ios::out | std::ios::binary | std::ios::trunc);
	if (arc.is_open())
	{
		mHeader.mFileName = source;
		mHeader.mFileNameLength = source.size();
		mHeader.mFileSize = size;

		arc.write(mHeader.mSig, 4);
		arc.write(reinterpret_cast<char*>(&(mHeader.mFileSize)), 4);
		arc.write(reinterpret_cast<char*>(&(mHeader.mFileNameLength)), 1);
		arc.write(mHeader.mFileName.c_str(), mHeader.mFileName.size());
		arc.write(mRleData.mData, mRleData.mSize);
	}


}
```