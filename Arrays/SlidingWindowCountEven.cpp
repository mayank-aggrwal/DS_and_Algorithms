
#include <iostream>
using namespace std;

void slidingCountEven(int *arr, int n, int k) {

    int count = 0;
    for(int i=0; i<k; i++) {
        if((arr[i] & 1) == 0)
            count++;
    }
    
    cout << "SLIDING WINDOW Count of even: ";
    cout << count << " ";
    for(int i=k; i<n; i++) {
        if((arr[i-k] & 1) == 0)
            count--;
        if((arr[i] & 1) == 0)
            count++;
        cout << count << " ";
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

    slidingCountEven(arr, n, k);

}