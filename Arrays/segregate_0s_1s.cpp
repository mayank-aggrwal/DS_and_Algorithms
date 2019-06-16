
#include <iostream>
using namespace std;

void segregate_01(int *arr, int n) {

    int i = 0, j = n-1;

    while(i < j) {
        while(arr[i] == 0)
            i++;
        while(arr[j] == 1)
            j--;
        if(i<j) {
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
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

    int arr[] = {0,0,1,0,1,1,1,0,0,1,0,1,1,0};
    int n = sizeof(arr)/sizeof(int);

    printArray(arr, n);
    segregate_01(arr, n);
    printArray(arr, n);

}