#include<utility>
#include <string>
#include <vector>
#include <algorithm>
#include <type_traits>
#include <iostream>
#include <functional>


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

  return 0;
}