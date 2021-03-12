#include<iostream>
#include<string>
#include<map>
#include "colors.h"

int main(int argc, char** argv) {
  std::map<std::string, std::string> m = {
	  {"CYAN", Color::CYAN},
	  {"MAGENTA", Color::MAGENTA},
	  {"BLUE", Color::BLUE},
	  {"YELLOW", Color::YELLOW},
	  {"GREEN", Color::GREEN},
	  {"RED", Color::RED},
	  {"PINK", Color::PINK},

	  {"BG_CYAN", BgColor::CYAN},
	  {"BG_MAGENTA", BgColor::MAGENTA},
	  {"BG_BLUE", BgColor::BLUE},
	  {"BG_YELLOW", BgColor::YELLOW},
	  {"BG_GREEN", BgColor::GREEN},
	  {"BG_RED", BgColor::RED},
	  {"BG_PINK", BgColor::PINK}
  };

  for (auto it = m.begin(); it != m.end(); ++it)
  {
	  std::cout << it->second << " " << it->first << "     " << Color::RESET << "\n";
  }
  
  // Trans Pride!

  std::cout << BgColor::BLUE << "                         \n";
  std::cout << BgColor::PINK << "                         \n";
  std::cout << BgColor::YELLOW << "                         \n";
  std::cout << BgColor::PINK << "                         \n";
  std::cout << BgColor::BLUE << "                         \n";
  std::cout << BgColor::RESET;
}
