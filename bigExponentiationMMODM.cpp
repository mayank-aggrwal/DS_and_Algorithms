// This example uses FERMAT'S LITTLE THEOREM AND BINARY EXPONENTIATION

#include <iostream>
#include <string>

using namespace std;
typedef long long lli;
#define M 1000000007
// 2^32 = 4294967296

lli modM(string a, int m) {
    lli ans = 0;
    for(int i=0; i<a.size(); i++) {
        int d = a[i]-48;
        ans = ans*10 + d;
        ans = ans%m;
    }
    return ans;
}

int binExp(int x, int n) {
    lli ans = 1, tmp = x;
    while(n) {
        if(n&1)
            ans = (ans*tmp)%M;
        tmp = (tmp*tmp)%M;
        n >>= 1;
    }
    return ans;
}

int exp(string a, string b) {
    // Calculate a mod M
    int x = modM(a, M);
    // cout << x << endl;

    //Calculate b mod M
    int n = modM(b, M-1);
    // cout << n << endl;

    // Calculate a^b using binary exponentiation
    return binExp(x, n);
}

int main() {
    string a, b;
    cout << "Enter a: ";
    cin >> a;
    cout << "Enter b: ";
    cin >> b;

    cout << "(a^b)mod m is: " << exp(a,b) << endl;

}