
#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;

// 0 <= x <= 2 ^ 31 - 1
double square_root(int x, int p) {
    lli s = 0, e = x, n = x;
    double ans = 0;

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

    double dec = 0.1;

    for (int i = 0; i < p; ++i) {
        double tmp = ans;
        while (tmp * tmp <= n) {
            ans = tmp;
            tmp += dec;
        }
        // cout << ans << endl;
        dec /= 10;
    }

    return ans;
}

int main () {
    int n = 5, p = 2;
    cout << "Square root of " << n << " is: " << square_root(n, 0) << endl;
    cout << "Square root of " << n << " is: " << square_root(n, 1) << endl;
    cout << "Square root of " << n << " is: " << square_root(n, 2) << endl;
    cout << "Square root of " << 50 << " is: " << square_root(50, 3) << endl;
    cout << "Square root of " << n << " is: " << fixed << setprecision(4) << square_root(n, 4) << endl;
    cout << "Square root of " << n << " is: " << fixed << setprecision(5) << square_root(n, 5) << endl;
    cout << "Square root of " << n << " is: " << fixed << setprecision(6) << square_root(n, 6) << endl;
    cout << "Square root of " << n << " is: " << fixed << setprecision(7) << square_root(n, 7) << endl;
    cout << "Square root of " << n << " is: " << fixed << setprecision(8) << square_root(n, 8) << endl;
}