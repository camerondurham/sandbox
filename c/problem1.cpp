#include<iostream>
int main() {

    int x = 1, sum = 0;

    while( x < 1000) {
        if(x%3 == 0 || x%5 == 0)
            sum += x;

        x++;
    }


    std::cout << "sum = " << sum << std::endl;


    return 0;

}
