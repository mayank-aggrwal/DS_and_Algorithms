
#include <iostream>
using namespace std;

void slidingSum(int *arr, int n, int k) {

    int sum = 0;
    for(int i=0; i<k; i++) 
        sum += arr[i];
    
    cout << "SLIDING WINDOW SUM: ";
    cout << sum << " ";
    for(int i=k; i<n; i++) {
        sum += arr[i] - arr[i-k];
        cout << sum << " ";
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

    slidingSum(arr, n, k);

}