
#include <iostream>
using namespace std;

int findWater(int *arr, int n, int p1, int p2) {
    int min = arr[p1]>arr[p2] ? arr[p2] : arr[p1];
    int ans = 0;
    for(int i=p1; i<=p2; i++) {
        int x = min-arr[i];
        if(x > 0) 
            ans += x;
    }
    return ans;
}

int trappedWater(int *arr, int n) {
    bool decAllowed = true, incAllowed = false;
    int ans = 0, p1, p2;

    for(int i=0; i<n-1;) {
        // cout << i;
        int x = arr[i], y = arr[i+1];

        if(x > y) {
            if(decAllowed && (!incAllowed)) {
                p1 = i;
                incAllowed = true;
                i++;
            }
            else if((!decAllowed) && incAllowed) {
                p2 = i;
                decAllowed = true;
                incAllowed = false;
                ans += findWater(arr, n, p1, p2);
            }
            else {
                i++;
            }
        }
        else if(x < y) {
            if(decAllowed && incAllowed) {
                decAllowed = false;
            }
            else if(decAllowed && (!incAllowed)) {
            }
            i++;
        }
        else{
            i++;
        }
    }
    return ans;
}

int main() {

    int arr[] = {0, 2, 1, 3, 0, 1, 2, 1, 2, 1};
    int arr1[] = {1,0,2,1,0,1,3,2,1,2,1,0};
    int n = sizeof(arr)/sizeof(int);
    int n1 = sizeof(arr1)/sizeof(int);
  
    int ans = trappedWater(arr1, n1);
    cout << "You can trap: " << ans << endl;

}