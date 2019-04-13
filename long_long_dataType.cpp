
#include <iostream>
using namespace std;

int main() {

    int i = 1000000007;
    cout << "i: 1000000007 actual: " << 1000000007 << endl;

    cout << "1000000007*1000000007 actual: " << 1000000007*1000000007 << endl;

    int j = 1000000007;
    int k = j * j;
    cout << "k=j*j: 1000000007*1000000007 actual: " << k << endl;

    cout << "j*j: 1000000007*1000000007 actual: " << 1.0*j*j << endl;

    cout << "j*j: 1000000007*1000000007 actual: " << (long long)j*j << endl;


}