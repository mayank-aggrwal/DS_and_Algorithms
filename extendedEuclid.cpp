
#include <iostream>
using namespace std;

int GCD(int a, int b, int &x, int &y) {
    
    if(b == 0) {
        x = 1;
        y = 0;
        return a;
    }

    int ans = GCD(b, a%b, x, y);
    int tmp = y;
    y = x - y*(a/b);
    x = tmp;
    return ans;
}

int main() {
    int a = 15068, b = 3456;
    int x, y;

    int gcd = GCD(a, b, x, y);

    cout << "GCD of " << a << " and " << b << " is: " << gcd << endl;
    cout << a << "*" << x << " + " << b << "*" << y << " = " << gcd << endl;

}