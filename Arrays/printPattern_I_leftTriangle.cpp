
#include <iostream>
using namespace std;

void printTriangle(int n) {

    int val = 1;
    for(int i=1; i<=n; i++) {
        for(int j=0; j<i; j++) {
            cout << val++ << " ";
        }
        cout << endl;
    }

}

int main() {

    int n = 5;
    cout << "Enter value of n: ";
    cin >> n;
    cout << "REQUIRED PATTERN IS: \n";
    printTriangle(n);

}