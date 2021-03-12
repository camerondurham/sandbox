#include<iostream>
#include<string>
#include<map>

const std::string COLOR_CYAN = "\u001b[36;1m";
const std::string COLOR_MAGENTA = "\u001b[35;1m";
const std::string COLOR_BLUE = "\u001b[34;1m";
const std::string COLOR_YELLOW = "\u001b[33;1m";
const std::string COLOR_GREEN = "\u001b[32;1m";
const std::string COLOR_RED = "\u001b[31;1m";
const std::string COLOR_PINK = "\u001b[38;5;206m";
const std::string COLOR_RESET = "\u001b[0m";

int main() {
  std::map<std::string, std::string> m = {
	  {"CYAN", COLOR_CYAN},
	  {"MAGENTA", COLOR_MAGENTA},
	  {"BLUE", COLOR_BLUE},
	  {"YELLOW", COLOR_YELLOW},
	  {"GREEN", COLOR_GREEN},
	  {"RED", COLOR_RED},
	  {"PINK", COLOR_PINK}
  };

  for (auto it = m.begin(); it != m.end(); ++it)
  {
	  std::cout << it->second << " " << it->first << COLOR_RESET << "\n";
  }

  // std::cout << COLOR_GREEN << " green " << COLOR_RED << " red " << COLOR_MAGENTA << " magenta " << COLOR_RESET << " reset\n";
}
