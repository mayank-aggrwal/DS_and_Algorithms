#include <bits/stdc++.h>
using namespace std;

int main() {
	//code
	
	int t, n, k;
	cin >> t;
	
	while(t--) {
	    cin >> n >> k;
	    int *arr = new int[n];
	    for(int i=0; i<n; i++) {
	        cin >> arr[i];
	    }
	    sort(arr, arr+n);
	    for(int i=n-1; i>=n-k; i--) {
	        cout << arr[i] << " ";
	    }
	    cout << endl;
	}
	
	return 0;
}