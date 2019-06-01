
#include <iostream>
#include <vector>

using namespace std;
#include "priority_queue.cpp"

int main() {
    
    pQueue<int> pq;
    int arr[] = {97,54,67,89,43,12,33,56,55,21,22,49,81,7};
    int n = sizeof(arr)/ sizeof(int);

    for(int i=0; i<n; i++)
        pq.push(arr[i]);

    pq.printPQ();

    cout << "Popping one by one: \n";
    for(int i=0; i<n; i++) {
        cout << pq.top() << " ";
        pq.pop();
    }

}