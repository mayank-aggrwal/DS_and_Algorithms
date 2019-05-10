// WAVE SORT is not a sorting algorithm

#include <iostream>
using namespace std;

void printArray(int *arr, int n) {

    cout << "ARRAY: ";
    for(int i=0; i<n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

}

void waveSort(int *arr, int n) {

    bool dec = true;
    for(int i=0; i<n-1; i++) {

        if(dec) {
            if(arr[i]<arr[i+1]) {
                swap(arr[i], arr[i+1]);
            }
        }
        else {
            if(arr[i]>arr[i+1]) {
                swap(arr[i], arr[i+1]);
            }
        }
        dec = !dec;

    }

}

int main() {

    // INPUT ARRAY TO BE WAVE ARRANGED
    int arr[] = {1,2,3,0,6,88,89,43,21};
    int n = sizeof(arr)/sizeof(int);
    printArray(arr, n);

    // WAVE ARRANGE THE GIVEN ARRAY
    waveSort(arr, n);

    // PRINT THE ARRANGED ARRAY
    cout << "After wave sort - ";
    printArray(arr, n);

}
