
#include <iostream>
using namespace std;

void swap(int *arr, int i, int j) {
    int tmp = arr[i];
    arr[i] = arr[j];
    arr[j] = tmp;
}

void selectionSort(int *arr, int n) {

    for(int i=0; i<n-1; i++) {
        int minIndex = i;
        for(int j=i; j<n; j++) {
            if(arr[j] < arr[minIndex]) 
                minIndex = j;
        }
        swap(arr, minIndex, i);
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
    selectionSort(arr, n);

    printArray(arr, n);

}