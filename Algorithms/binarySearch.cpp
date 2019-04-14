
#include <iostream>
using namespace std;

int binarySearch(int *arr, int n, int element) {
    int s = 0, e = n-1;
    while(s <= e) {
        int mid = (s+e)/2;
        if(arr[mid] == element)
            return mid;
        else if(arr[mid] > element) 
            e = mid - 1;
        else
            s = mid + 1;
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
    
    int index = binarySearch(arr, n, element);
    if(index == -1) {
        cout << "Element not found" << endl;
    }
    else {
        cout << "Element found at index: " << index << endl;
    }

}