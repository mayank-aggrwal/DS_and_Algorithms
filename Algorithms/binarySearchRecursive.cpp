
#include <iostream>
using namespace std;

int binarySearchRecursive(int arr[], int n, int element) {

    int mid = (n-1)/2;
    if(arr[mid] == element) {
        return mid;
    }

    if(arr[mid] > element) {
        return binarySearchRecursive(arr, (n-1)/2, element);
    }
    else {
        int ans = binarySearchRecursive(arr+mid+1, n/2, element);
        return ans + mid + 1;
    }

}

void printArray(int *arr, int n) {
    cout << "Array: ";
    for(int i=0; i<n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {

    int arr[] = {12, 45, 46, 49, 61 , 69, 74, 81, 99};
    int n = sizeof(arr)/sizeof(int);
    printArray(arr, n);

    int element = 81;
    cout << "Element to find: " << element << endl;

    int index = binarySearchRecursive(arr, n, element);

    if(index == -1) {
        cout << "Element not found" << endl;
    }
    else {
        cout << "Element found at index: " << index << endl;
    }

}