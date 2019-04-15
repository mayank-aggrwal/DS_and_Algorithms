#include <iostream>
#include <unordered_map>

using namespace std;

void printArray(int *arr, int n) {
    cout << "Array: ";
    for(int i=0; i<n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int findHighestFreqNum(int *arr, int n) {
    unordered_map<int, int> map;
    for(int i=0; i<n; i++) {
        if(map.count(arr[i]) == 0) 
            map[arr[i]] = 1;
        else 
            map[arr[i]]++;
    }
    int freq = 0, ans = INT32_MIN;
    for(int i=0; i<n; i++) {
        if(map[arr[i]] > freq) 
            ans = arr[i];
    }
    return ans;
}

int main() {

    int arr[] = {1,6,8,1,8,9,2,8,8,9,1,9,1};
    int n = sizeof(arr)/sizeof(int);

    printArray(arr, n);

    cout << "Most frequently occuring number: " << findHighestFreqNum(arr, n);

}