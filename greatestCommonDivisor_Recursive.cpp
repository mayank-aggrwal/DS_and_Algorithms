
#include <iostream>
using namespace std;

// int gcd(int a, int b) {
//     if(b == 0) {
//         return a;
//     }
//     return gcd(b, a%b);
// }

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a%b);
}

int main() {

    int a, b;
    cout << "Enter a: ";
    cin >> a;
    cout << "Enter b: ";
    cin >> b;

    cout << "Greatest Common Divisor : " << gcd(a, b) << endl;

}