#include <iostream>     // std::cin, std::cout
#include<queue>
#include<unordered_set>

void showq(std::queue<int> &gq);

void show_string_set(std::unordered_set<std::string> string_set){

  for(const std::string& x : string_set){
          std::cout << x << " ";
  }

  std::cout << "\n";
}

int main () {

  // istream::ignore example from http://www.cplusplus.com/reference/istream/istream/ignore/
  // extracts characters from input sequences and discards them
/*
  char first, last;

  std::cout << "Please, enter your first name followed by your surname: ";

  first = std::cin.get();     // get one character
  std::cin.ignore(256,' ');   // ignore until space

  last = std::cin.get();      // get one character

  std::cout << "Your initials are " << first << last << '\n';


  //////////////////////////////////////////////////////////////////////////////
                       // QUEUE
  //////////////////////////////////////////////////////////////////////////////


  std::queue<int> gquiz;
  gquiz.push(10);
  gquiz.push(20);
  gquiz.push(30);

  std::cout<< "\nThe front of the queue is: " << gquiz.front() << std::endl;

  std::cout<< "Ths queue is: ";
  showq(gquiz);
  */

  //////////////////////////////////////////////////////////////////////////////
  //                         UNORDERED SET
  //////////////////////////////////////////////////////////////////////////////

  std::cout<< "Unordered sets are containers storing unique elements ";
  std::cout << "in no particular order.\n\nThis allows for fast retrieval ";
  std::cout << "of elements based on their value.";

  std::unordered_set<std::string> simple;


  std::string list("abcddddcbaz");
  std::cout << "\n\nEntering these letters into a character set: " << list << "\n";

  for(char c : list){
          std::string s((const char*) &c);
          simple.insert(s);
  }

  show_string_set(simple);

  std::cout << "Now removing an element: letter 'a' \n";

  simple.erase("a");

  std::cout << "\nContents now: ";

  show_string_set(simple);

  return 0;

}


void showq(std::queue<int>& gq){
    std::queue<int> g = gq;
      while(!g.empty()){
          std::cout<< '\t' << g.front();
          g.pop();
      }
      std::cout << '\n';

  }


