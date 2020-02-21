#include <fstream>
#include <iostream>
#include <string>
#include <stack>

void printFile(std::string);
void printArray(std::string**, int SIZE);

int main () {
    int SIZE = 4;

    std::string** string = new std::string * [SIZE];
    for(int i = 0; i < SIZE; ++i){
        string[i] = new std::string[SIZE];
    }

    for(int i = 0; i < SIZE; ++i){
        for(int j = 0; j < SIZE; ++j){
            string[i][j] = "hello";
        }
    }

    printArray(string, SIZE);

    for(int i = 0; i < SIZE; ++i){
        delete [] string[i];
    }

    delete [] string;

}

// simple function to print characters in a file
void printFile(std::string filename){

    if(filename.length() == 0){
        std::cout << "invalid filename\n";
        return;
    }

    std::ifstream file(filename);

    if( !file.is_open()){
        std::cout << "invalid filename\n";
        return;
    }

    std::string str;
    std::stack<char> stack;

    while( getline(file, str) ){
        for(char c : str){
            stack.push(c);
        }
    }

    while(!stack.empty()){
        char c = stack.top();
        stack.pop();
        std::cout << c;
    }
    std::cout << '\n';
}

void printArray(std::string ** array, int SIZE){
    for(int i = 0; i < SIZE; ++i){
        for(int j = 0; j < SIZE; ++j){
            std::cout << array[i][j] << "  ";
        }
        std::cout << '\n';
    }
}
