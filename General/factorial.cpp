#include <iostream>
using namespace std;

typedef long long lli;

lli factorial(int n) {
    lli ans = 1;
    while(n > 1) {
        ans *= n;
        n--;
    }
    return ans;
}

int main() {
	//code
	int t;
	cin >> t;
	while(t--) {
	    int n;
	    cin >> n;
	    cout << factorial(n) << endl;
	}
	return 0;
}