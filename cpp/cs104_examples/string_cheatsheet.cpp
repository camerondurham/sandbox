// string::erase
#include <iostream>
#include <string>
#include <stdio.h>

/*
 *  important string functions:
 *  append("Cote")
 *  push_back('C')
 *  pop_back()
 *  insert(s.begin() + shift, "Cote")
 *  substr(pos, len)
 *  compare("Cote")
 *
 *  UPDATING MUTABLE STRINGS FROM THE FRONT IS SLOW
 *  TRY TO WRITE FROM THE BACK
 *
 */

int main ()
{
  std::string str ("uuuuxaaaaaxuuuu");
  std::cout << str << '\n';
                                           // "This is an sentence."
  str.erase (str.begin()+9);               //           ^
  std::cout << str << '\n';
                                           // "This is a sentence."
  str.erase (str.begin()+5, str.end()-9);  //       ^^^^^
  std::cout << str << '\n';

  std::string professors("Batista ");
  std::cout << "Before: " << professors << '\n';
  professors.append("Cote ");
  std::cout << "After append: " << professors << '\n';
  professors.push_back('!');
  std::cout << "After push back: " << professors << '\n';

  std::string str2 = professors.substr(8,4);
  std::cout << "Substring with indicies: " << str2 << '\n';
  std::size_t pos = professors.find("ista");
  std::string str3 = professors.substr(pos);
  std::cout << "After finding the end of her name: " << str3 << '\n';

  str3 = professors.substr(pos,4);
  std::cout << "After finding the end of her name length 4: " << str3 << '\n';
  return 0;
}
