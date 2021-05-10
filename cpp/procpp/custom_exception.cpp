#include <exception>

class MyMemoryException : public std::exception
{
  const char* what() const noexcept override 
  {
    return "My memory exception";
  }
};