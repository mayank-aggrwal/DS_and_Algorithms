
#include <iostream>
using namespace std;

int nthFibo(int n) {
    int a = 0, b = 1, next;
    if(n == 0 || n == 1) {
        return n;
    }
    for(int i=2; i<=n; i++) {
        next = a + b;
        a = b;
        b = next;
    }
    return next;
}

int main() {
    int n;
    cin >> n;

    cout << "Nth fibonacci number is: " << nthFibo(n) << endl;

}