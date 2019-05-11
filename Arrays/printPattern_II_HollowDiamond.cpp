
#include <iostream>
using namespace std;

void printHollowDiamond(int n) {

    // NUMBER OF LINES IN FIRST AND SECOND HALF OF DIAMOND 
    n = (n-1)/2;

    // PRINT UPPER HALF
    for(int i=0; i<n; i++) {
        int j;

        // PRINT SERIES OF SPACES
        for(j=0; j<n-i; j++) {
            cout << " ";
        }

        // PRINT ONE STAR
        cout << "*";

        // PRINT SERIES OF SPACES
        for(j=0; j<(2*i-1); j++) {
            cout << " ";
        }

        // PRINT STAR IF NOT FIRST LINE WHICH CONTAINS SINGLE STAR
        if(i != 0)
            cout << "*";      
        cout << endl;
    }

    // PRINT MIDDLE PORTION
    cout << "*";
    for(int i=0; i<(2*n-1); i++) {
        cout << " ";
    }
    cout << "*\n";

    // PRINT LOWER HALF
    for(int i=0; i<n; i++) {
        int j;

        // PRINT SERIES OF SPACES
        for(j=0; j<i+1; j++) {
            cout << " ";
        }

        // PRINT ONE STAR
        cout << "*";

        // PRINT SERIES OF SPACES
        for(j=0; j<(2*n-2*i-3); j++) {
            cout << " ";
        }

        // PRINT STAR IF NOT LAST LINE WHICH CONTAINS SINGLE STAR
        if(i != n-1)
            cout << "*";
        cout << endl;
    }

}

int main() {

    int n = 9;

    // N MUST BE AN ODD NUMBER
    cin >> n;

    printHollowDiamond(n);

}