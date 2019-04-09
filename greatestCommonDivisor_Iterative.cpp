
#include <iostream>
using namespace std;

int gcd(int a, int b) {
    while(b) {
        int tmp = a;
        a = b;
        b = tmp%b;
    }
    return a;
}

int main() {

    int a, b;
    cout << "Enter a: ";
    cin >> a;
    cout << "Enter b: ";
    cin >> b;

    cout << "Greatest Common Divisor : " << gcd(a, b) << endl;

}