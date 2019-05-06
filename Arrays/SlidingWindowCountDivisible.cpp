
#include <iostream>
using namespace std;

void slidingCountDivisible(int *arr, int n, int k, int d) {

    int count = 0;
    for(int i=0; i<k; i++) {
        if((arr[i]%d) == 0)
            count++;
    }
    
    cout << "SLIDING WINDOW Count of divisible no. : ";
    cout << count << " ";
    for(int i=k; i<n; i++) {
        if((arr[i-k]%d) == 0)
            count--;
        if((arr[i]%d) == 0)
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

    int arr[] = {1,12,33,48,5,60,7,18,9};
    int k = 3, d = 6;
    int n = sizeof(arr)/sizeof(int);
    printArray(arr, n);

    slidingCountDivisible(arr, n, k, d);

}