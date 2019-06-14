#include <iostream>
#include <cmath>
using namespace std;

int main() {
    
	int t;
	cin >> t;
	
	while(t--) {
	    int n, tmp;
	    cin >> n;
	    for(int i=0; i<n; i++) {
	        cin >> tmp;
	    }
	    cout << (int)log2(n) << endl;
	}
	
	return 0;
}