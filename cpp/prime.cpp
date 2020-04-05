#include <iostream>
#include <vector>
using namespace std;

void form_sieve(int A, int* prime){
    for(int c = 0; c < A; c++)
        prime[c] = 1;
    prime[0] = 0;
    prime[1] = 0;
    for(int p = 2; p * p <= A; p++){
        if(prime[p] == 1){
            // update all multiples of p
            for(int i = p * p; i <= A; i += p)
                prime[i] = 0;
        }
    }
}

void primesum(int A) {
    // find prime numbers less than A
    // use sieve method
    int* prime = new int[A + 1];
    form_sieve(A, prime);
    vector<int> result;
    // for(int c = 0; c <= A; c++)
    //     cout << prime[c] << "\n";


    for(int i = 2; i <= A; i++){
        if(prime[i]){
            if(i + i == A){
                result.push_back(i);
                result.push_back(i);
                break;
            }
            else if(prime[A - i]){
                result.push_back(i);
                result.push_back(A - i);
                break;
            }
        }

    }
    // cout << result.size();
    for(vector<int>::iterator ptr =  result.begin(); ptr < result.end(); ptr++){
        cout << *ptr << "\n";
    }
    // return result;
}


// Driver Code
int main()
{
    primesum(16777214);
}
