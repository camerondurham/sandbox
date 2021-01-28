#include<utility>
#include <string>
#include <vector>
#include <algorithm>
#include <type_traits>
#include <iostream>
#include <functional>
#include <numeric>


struct Student
{
	std::string FirstName;
	std::string LastName;

	friend bool operator<(const Student& a, const Student& b)
	{
		if (a.LastName == b.LastName)
		{
			return a.FirstName < b.FirstName;
		}
		else
		{
			return a.LastName < b.LastName;
		}
	}
};

struct StudentSorter
{
	int SortOrder;
	static int Count;

	bool operator()(const Student& a, const Student& b)
	{
			Count++;
			// if 0 sort normal way
			if (SortOrder == 0)
			{
					return a < b;
			}
			else
			{
				if (a.LastName == b.LastName)
				{
					return a.FirstName < b.FirstName;
				}
				else
				{
					return a.LastName < b.LastName;
				}
			}
	}
};

int StudentSorter::Count = 0;

class Event
{
public:
		void AddHandler(std::function<void()> f)
		{
			mHandlers.push_back(f);
		}

		void Trigger()
		{
			for(auto f : mHandlers)
			{
				f();
			}
		}

private:
		std::vector<std::function<void()>> mHandlers;
};


int main(int argc, char** argv)
{
  std::vector<Student> students{
    {"Mary", "Smith"},
    {"John", "Doe"},
    {"James", "Miller"}
  };

	std::vector<int> randomNums(50, -1);
	std::generate(randomNums.begin(), randomNums.end(), [](){
		return std::rand();
	});

  std::vector<int> numbers{5,-5,20,35,17};

	int Count = 0;
	std::string Name;

	std::function<bool(const Student&, const Student&) > myLambda =
	[](const Student& a, const Student& b){
				if (a.LastName == b.LastName)
				{
					return a.FirstName < b.FirstName;
				}
				else
				{
					return a.LastName < b.LastName;
				}
	};

  // std::sort(numbers.begin(), numbers.end(), std::greater<int>());
  std::sort(students.begin(), students.end(), myLambda);

	Event e;
	int Count2 = 0;
	e.AddHandler([&Count2]{
		Count2++;
		std::cout << "Handler1!" << std::endl;
	});
	e.AddHandler([&Count2]{
		Count2++;
		std::cout << "Handler2!" << std::endl;
	});
	e.AddHandler([&Count2]{
		Count2++;
		std::cout << "Handler3!" << std::endl;
	});

	e.Trigger();


  // if (LessThan(a,b)) then swap
  // LessThan is a "binary predicate"
  // predicate -> returns true or false
  // binary -> takes in two parameters

	for(const auto& s : students)
	{
		std::cout<< s.LastName << " , " << s.FirstName << std::endl;
	}

	std::vector<int> v{2,4,6,8,10};
	std::vector<int> vdest;
	// back inserter automatically pushes back, makes size correct in the end
	std::copy_n(v.begin(), 3, std::back_inserter(vdest));
	for (const auto& vv : vdest)
	{
		std::cout << vv << " ";
	}
	std::cout << "\n";

	std::vector<int> v3(10);

	// reference: https://www.cplusplus.com/reference/numeric/iota/
	// increments: {0, 1, 2, ... , 9}
	std::iota(v3.begin(), v3.end(), 0);

	for(const auto &i : v3)
	{
		std::cout << i << " ";
	}
	std::cout << "\n";

	std::vector<std::vector<int>> myVecs(5);

	// Generate each inner vector
	std::generate(myVecs.begin(), myVecs.end(), [] {
		// Populate the inner vector with 0-9
		std::vector<int> temp(10);
		std::iota(temp.begin(), temp.end(), 0);
		return temp;
	});

	for(const auto &a : myVecs)
	{
		for(const auto &b : a)
		{
			std::cout << b << " ";
		}
		std::cout << "\n";
	}

  return 0;
}