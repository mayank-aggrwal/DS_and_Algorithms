
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int>* findUniqueElements(int *arr, int n) {
    vector<int> *a = new vector<int>();
    unordered_map<int, bool> hmap;
    for(int i=0; i<n; i++) {
        if(hmap.count(arr[i]) == 0) {
            hmap[arr[i]] = true;
            a -> push_back(arr[i]);
        }
    }

    // GENERATES RANDOM ORDERING
    // for(auto i=hmap.begin(); i!=hmap.end(); i++) {
    //     a -> push_back(i->first);
    // }
    return a;
}

int main() {

    int arr[] = {1,3,6,5,3,1,1,5,8,7,6,6,5,1};
    int n = sizeof(arr)/sizeof(int);

    vector<int> *ans = findUniqueElements(arr, n);

    for(int i=0; i<ans->size(); i++) {
        cout << ans -> at(i) << " ";
    }
    cout << endl;
}