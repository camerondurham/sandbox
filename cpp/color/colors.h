#include<string>

struct Color {
	static const std::string CYAN;
	static const std::string MAGENTA;
	static const std::string BLUE;
	static const std::string YELLOW;
	static const std::string GREEN;
	static const std::string RED;
	static const std::string PINK;
	static const std::string RESET;
};

const std::string Color::CYAN =  "\u001b[36;1m";
const std::string Color::MAGENTA = "\u001b[35;1m";
const std::string Color::BLUE = "\u001b[34;1m";
const std::string Color::YELLOW = "\u001b[38;5;226m";
const std::string Color::GREEN = "\u001b[38;5;46m";
const std::string Color::RED = "\u001b[38;5;196m";
const std::string Color::PINK = "\u001b[38;5;206m";
const std::string Color::RESET = "\u001b[0m";

struct BgColor {
	static const std::string CYAN;
	static const std::string MAGENTA;
	static const std::string BLUE;
	static const std::string YELLOW;
	static const std::string GREEN;
	static const std::string RED;
	static const std::string PINK;
	static const std::string WHITE;
	static const std::string BLACK;
	static const std::string RESET;
};


const std::string BgColor::CYAN = "\u001b[48;5;14m";
const std::string BgColor::MAGENTA = "\u001b[48;5;13m";
const std::string BgColor::BLUE = "\u001b[48;5;27m";
const std::string BgColor::YELLOW = "\u001b[48;5;11m";
const std::string BgColor::GREEN = "\u001b[48;5;10m";
const std::string BgColor::RED = "\u001b[48;5;9m";
const std::string BgColor::PINK = "\u001b[48;5;207m";
const std::string BgColor::WHITE = "\u001b[48;5;255m";
const std::string BgColor::BLACK = "\u001b[48;5;0m";
const std::string BgColor::RESET = "\u001b[0m";

