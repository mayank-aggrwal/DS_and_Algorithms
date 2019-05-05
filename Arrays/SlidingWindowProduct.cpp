
#include <iostream>
using namespace std;

void slidingProduct(int *arr, int n, int k) {

    int product = 0;
    for(int i=0; i<k; i++) 
        product += arr[i];
    
    cout << "SLIDING WINDOW Product: ";
    cout << product << " ";
    for(int i=k; i<n; i++) {
        product = (product*arr[i]) / arr[i-k];
        cout << product << " ";
    }

}

void printArray(int *arr, int n) {

    cout << "ARRAY: ";
    for(int i=0; i<n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

}

int main() {

    int arr[] = {1,2,3,4,5,6,7,8,9};
    int k = 3;
    int n = sizeof(arr)/sizeof(int);
    printArray(arr, n);

    slidingProduct(arr, n, k);

}