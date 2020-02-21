
#include<iostream>
using namespace std;

int main() {
    int ** heap_array = new int *[9];

    int stack_array [3][3];

    for(int i = 0;i<3;i++){
        for(int j=0;j<3;j++){
            stack_array[i][j] = 3*i + j + 1;
        }
    }

    for(int i = 0 ; i < 9 ; i++){
             *(heap_array + i) = *(stack_array + i/3 + i%3);
    }

    for(int i = 0;i<3;i++){
        for(int j=0;j<3;j++){
            cout << stack_array[i][j] << " ";
        }
        cout<<endl;
    }



    for(int i = 0; i<9 ;i++){
        if(i%3 == 0)
            cout << endl;

        cout << *( *(heap_array + (i/3)) + (i%3)) << " ";
   }


    delete [] heap_array;



    return 0;
}







