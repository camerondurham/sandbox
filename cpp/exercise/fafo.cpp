#include<iostream>
#define fuckaround try
#define findout catch

int main()
{
  fuckaround
  {
    throw "ah shit";
  } 
  findout(const char* s)
  {
      std::cout << s << std::endl;
  }
}