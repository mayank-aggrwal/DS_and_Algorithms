#include <iostream>
using namespace std;

void mergePrintSortedArray(int *a, int *b, int x, int y) {
    
    int i, j;
    i = j = 0;
    while((i<x) && (j<y)) {
        if(a[i] < b[j]) {
            cout << a[i] << " ";
            i++;
        }
        else {
            cout << b[j] << " ";
            j++;
        }
    }
    if(i < x) {
        for(; i<x; i++) {
            cout << a[i] << " ";
        }
    }
    if(j < y) {
        for(; j<y; j++) {
            cout << b[j] << " ";
        }
    }
    cout << endl;
}

int main() {
	
	int t, x, y;
	cin >> t;
	while(t--) {
	    
	    cin >> x >> y;
	    int *a = new int[x];
	    int *b = new int[y];
	    
	    for(int i=0; i<x; i++) {
	        cin >> a[i];
	    }
	    for(int i=0; i<y; i++) {
	        cin >> b[i];
	    }
	    
	    mergePrintSortedArray(a, b, x, y);
	}
	
	return 0;
}