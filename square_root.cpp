
#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;

// 0 <= x <= 2 ^ 31 - 1
int square_root(int x) {
    lli s = 0, e = x, n = x;
    int ans = 0;

    while (s <= e) {
        lli mid = s + (e - s) / 2;
        if (mid * mid > n) {
            e = mid - 1;
        }
        else if (mid * mid == n) {
            ans = mid;
            break;
        }
        else {
            ans = mid;
            s = mid + 1;
        }
    }

    return ans;
}

int main () {
    int n = 5;
    cout << "Square root of " << n << " is: " << square_root(n) << endl;
}