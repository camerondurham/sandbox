#include<iostream>
#include<string>

const std::string COLOR_CYAN = "\u001b[36;1m";
const std::string COLOR_MAGENTA = "\u001b[35;1m";
const std::string COLOR_BLUE = "\u001b[34;1m";
const std::string COLOR_YELLOW = "\u001b[33;1m";
const std::string COLOR_GREEN = "\u001b[32;1m";
const std::string COLOR_RED = "\u001b[31;1m";
const std::string COLOR_RESET = "\u001b[0m";

int main() {
  std::cout << COLOR_GREEN << " green " << COLOR_RED << " red " << COLOR_MAGENTA << " magenta " << COLOR_RESET << " reset\n";
}