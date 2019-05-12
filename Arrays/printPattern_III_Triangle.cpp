
#include <iostream>
using namespace std;

void printPattern(int n) {

    for(int i=0; i<n; i++) {
        int j;
        for(j=0; j<n-i-1; j++) {
            cout << " ";
        }
        for(j=1; j<= 2*i+1; j++) {
            cout << "*";
        }
        cout << endl;
    }

}

int main() {

    int n;
    cout << "Enter the number of rows: ";
    cin >> n;

    printPattern(n);
}