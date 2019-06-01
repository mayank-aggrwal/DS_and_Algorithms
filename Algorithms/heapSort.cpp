
#include <iostream>
using namespace std;

void swap(int *arr, int m, int n) {
    int tmp = arr[m];
    arr[m] = arr[n];
    arr[n] = tmp;
}

void heapify(int i, int *arr, int n) {
    int leftchildIndex = 2*i+1;
    int rightchildIndex = leftchildIndex+1;
    int maxIndex = i;

    if(leftchildIndex < n  && arr[leftchildIndex] > arr[maxIndex]) {
        maxIndex = leftchildIndex;
    }
    if(rightchildIndex < n  && arr[rightchildIndex] > arr[maxIndex]) {
        maxIndex = rightchildIndex;
    }

    if(maxIndex != i) {
        swap(arr, maxIndex, i);
        heapify(maxIndex, arr, n);
    }

}

void heapSort(int *arr, int n) {

    int x = (n-2)/2;
    for(int i=x; i>=0; i--) {
        heapify(i, arr, n);
    }

    for(int i=0; i<n-1; i++) {
        swap(arr, 0, n-i-1);
        heapify(0, arr, n-i-1);
    }

}

void printArray(int *arr, int n) {
    cout << "List: ";
    for(int i=0; i<n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {

    int arr[] = {97,54,67,89,43,12,33,56,55,21,22,49,81,7};
    int n = sizeof(arr)/ sizeof(int);

    printArray(arr, n);

    cout << "Array after sorting: \n";
    heapSort(arr, n);

    printArray(arr, n);

}