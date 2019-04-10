
//GIVEN AN ARRAY OF INTEGERS WHERE EVERY NUMBER APPEARS TWICE EXCEPT TWO. FIND THE TWO NUMBERS IN THE ARRAY.

#include <iostream>
using namespace std;

pair<int, int>* find2UniqueNumber(int *arr, int n) {
    
    int x = 0;
    for(int i=0; i<n; i++) {
        x ^= arr[i];
    }
    int firstSetBit = -1, tmp = x;
    while(tmp) {
        firstSetBit++;
        if(tmp & 1) {
            break;
        }
        tmp >>= 1;
    }

    int first = 0;
    for(int i=0; i<n; i++) {
        if(arr[i] & (1 << firstSetBit)) {
            first ^= arr[i];
        }
    }

    pair<int, int> *p = new pair<int, int>;
    p -> first = first;
    p -> second = x ^ first;
    return p; 

}

void printArray(int *arr, int n) {
    cout << "Array: ";
    for(int i=0; i<n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int n = 12;
    int arr[12] = {1,7,5,3,1,5,9,8,8,4,3,7};
    printArray(arr, sizeof(arr)/sizeof(int));
    pair<int, int> *p1 = find2UniqueNumber(arr, n);
    cout << "The 2 unique numbers in the array are: " << p1 -> first <<" and " << p1 -> second <<" . " << endl;

}