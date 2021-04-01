// calc.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include "node.h"
#include "parser.hpp"
#include <stack>
#include <string>
#include <fstream>

extern Node* g_Result;

extern int calcparse();
extern FILE* calcin;

int main(int argc, char* argv[])
{
	// Read input from first command line parameter
	calcin = fopen(argv[1], "r");
	if (calcin == nullptr)
	{
		std::cout << "File not found: " << argv[1] << std::endl;
		return 0;
	}
	calcparse();
	if (g_Result != nullptr)
	{
		std::cout << "Result = ";
		g_Result->debugOut();
		std::cout << std::endl;

		std::cout << "------------------------------------------------" << std::endl;
		std::ofstream file("test.cpp");
		CodeContext c;
		g_Result->codeGen(c);

		// Build output cpp file with __asm block
		file << "#include <iostream>" << std::endl << std::endl;
		file << "int main()" << std::endl;
		file << "{" << std::endl;
		file << "\tint result = 0;" << std::endl;
		file << "\t__asm" << std::endl;
		file << "\t{" << std::endl;

		for (auto i = c.ops.begin();
			i != c.ops.end();
			++i)
		{
			std::cout << *i << std::endl;
			file << "\t\t" << *i << std::endl;
		}

		file << "\t\tpop result" << std::endl;
		file << "\t}" << std::endl << std::endl;
		file << "\tstd::cout << \"Result = \" << result << std::endl;" << std::endl;
		file << "\treturn 0;" << std::endl;
		file << "}" << std::endl << std::endl;
	}
	// Close the file stream
	fclose(calcin);
	
	return 0;
}

void calcerror(const char* s)
{
	std::cout << s << std::endl;
}
