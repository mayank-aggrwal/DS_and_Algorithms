
#include <iostream>
#include <queue>
using namespace std;

int kthSmallest(int *arr, int n, int k) {

    if(k > n) {
        return INT32_MAX;
    }

    int i = 0;
    priority_queue<int, vector<int>, greater<int>> pq;
    for(; i<k; i++) {
        pq.push(arr[i]);
    }

    for(; i<n; i++) {
        if(pq.top() < arr[i]) {
            pq.pop();
            pq.push(arr[i]);
        }
    }

    return pq.top();

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
    int k = 5;

    printArray(arr, n);

    cout << "kth smallest : " << kthSmallest(arr, n, k) << endl;
}