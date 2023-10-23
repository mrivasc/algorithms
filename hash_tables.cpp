#include <iostream>
#include "test_array.hpp"
using namespace std;

int hashFunction(int v) {
    return v % nmax;
}

bool hashTableSearch(int* A, int v) {
    int hash = hashFunction(v);
    // //cout << "Hash value: " << hash << "\n";

    return A[hash] == v;
}

int main() {
    int HT[nmax];

    // Input a number to search
    int v;
    cout << "Search for: "; 
    cin >> v;
    
    // Create the Hash Table
    for(int i=0; i<n; ++i) {
        HT[ hashFunction(A[i]) ] = v;
    }

    // Search the number
    if(v <= nmax && hashTableSearch(HT, v)) cout << "Value found!";
    else cout << "Value not found :(";

    return 0;
}