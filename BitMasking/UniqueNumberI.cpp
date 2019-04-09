
//GIVEN AN ARRAY OF INTEGERS WHERE EVERY NUMBER APPEARS TWICE EXCEPT ONE. FIND THAT UNIQUE NUMBER IN THE ARRAY.

#include <iostream>
using namespace std;

int findUniqueNumber(int *arr, int n) {
    int ans = 0;
    for(int i=0; i<n; i++) {
        ans ^= arr[i];
    }
    return ans;
}

void printArray(int *arr, int n) {
    cout << "Array: ";
    for(int i=0; i<n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int n = 10;
    int arr[11] = {1,7,5,3,1,5,9,8,8,3,7};
    printArray(arr, sizeof(arr)/sizeof(int));

    cout << "The unique number in the array is: " << findUniqueNumber(arr, 11) << endl;

}