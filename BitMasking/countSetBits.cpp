
#include <iostream>
using namespace std;
typedef unsigned long long lli;

int countSetBits(lli n) {
    int count = 0;
    while(n > 0) {
        count += (n & 1);
        n >>= 1;
    }
    return count;
}

int modifiedCountSetBits(lli n) {
    int count = 0;
    while(n > 0) {
        count++;
        n = (n & (n-1));
    }
    return count;
}

int main() {
    lli n;
    cout << "Enter number to count set bits in: ";
    cin >> n;
    cout << countSetBits(n) << endl;
    cout << modifiedCountSetBits(n) << endl;
}