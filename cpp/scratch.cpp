#include <fstream>
#include <iostream>
#include <string>
#include <cstring>

void printFile(std::string );

int main () {
    // std::stringstream ss;
    // ss << 100 << ' ' << 200;

    // int foo, bar;
    // ss >> foo >> bar;

    // std::cout << "foo: " << foo << '\n';
    // std::cout << "bar: " << bar << '\n';
    std::cout << "hello world" << std::endl;
}

// simple function to print characters in a file
void printFile(std::string filename){

    std::ifstream file(filename);

    std::string str;
    while( getline(file, str) ){
        for(char c : str){
            std::cout << " " << c ;
        }
        std::cout << '\n';
    }
}
