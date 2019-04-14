
#include <iostream>
using namespace std;

int linearSearch(int *arr, int n, int element) {
    for(int i=0; i<n; i++) {
        if(arr[i] == element) {
            return i;
        }
    }
    return -1;
}

void printArray(int *arr, int n) {
    cout << "Array: ";
    for(int i=0; i<n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {

    int arr[] = {1,5,9,23,45,49,51,58,73,79,80,95};
    int n = sizeof(arr)/sizeof(int);
    printArray(arr, n);
    
    int element = 9;
    cout << "Enter the element to search: ";
    cin >> element;

    int index = linearSearch(arr, n, element);
    if(index == -1) {
        cout << "Element not found" << endl;
    }
    else {
        cout << "Element found at index: " << index << endl;
    }

}