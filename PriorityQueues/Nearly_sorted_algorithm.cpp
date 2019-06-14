#include <iostream>
#include <queue>
using namespace std;

// class ele {
//     public:
//     int val, pos;
//     ele(int a, int b) {
//         val = a;
//         pos = b;
//     }
//     ele() {
//         val = 0;pos = 0;
//     }
// };

// class comp {
//     public:
//     bool operator()(ele a, ele b) {
//         return a.val > b.val;
//     }
// };


void sortArray(int *arr, int n, int k) {
    int i;
    priority_queue<int, vector<int>, greater<int>> pq;
    for(i=0; (i<n && i<=k); i++) {
        pq.push(arr[i]);
    }
    int z = 0;
    int tmp;
    while(i<n) {
        tmp = pq.top();
        pq.pop();
        arr[z++] = tmp;
        pq.push(arr[i++]);
    }
    
    while(!pq.empty()) {
        tmp = pq.top();
        pq.pop();
        arr[z++] = tmp;
    }
}

int main() {
	//code
	
	int t, n, k, tmp;
	cin >> t;
	while(t--) {
	   cin >> n >> k;
	   int *arr = new int[n];
	   for(int i=0; i<n; i++) {
	       cin >> arr[i];
	   }
	   sortArray(arr, n, k);
	   for(int i=0; i<n; i++) {
	       cout << arr[i] << " ";
	   }
	   cout << endl;
	}
	
	return 0;
}