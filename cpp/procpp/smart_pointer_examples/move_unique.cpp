#include <memory>
#include <iostream>
class MyClass {
public:
 MyClass() { std::cout << "Constructor\n"; }
 ~MyClass() { std::cout << "Destructor\n"; }
 void PrintType() { std::cout << "MyClass\n"; }
};
 
void Print(std::unique_ptr<MyClass> res) {
 if (res != nullptr) {
   res->PrintType();
 }
}
 
int main() {
 std::unique_ptr<MyClass> ptr(new MyClass());
 
 Print(std::move(ptr));
 std::cout << "Finish\n";
 
 return 0;
}


/*
Output:
  Constructor
  MyClass
  Destructor
  Finish
*/