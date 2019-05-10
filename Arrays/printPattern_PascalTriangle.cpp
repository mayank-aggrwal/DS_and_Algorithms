
#include <iostream>
using namespace std;

void printPascalTriangle(int n) {

    if(n <= 0)
        return ;

    cout << 1 << endl;
    if(n == 1) {
        return ;
    }

    cout << 1 << " " << 2 << " " << 1 << endl;
    if(n == 2) {
        return ;
    }

    int *a = new int[n+1];
    a[n] = 1;
    a[n-1] = 2;
    a[n-2] = 1;

    for(int j=n-2; j>0; j--) {
        int i = j;
        a[i-1] = 1;
        for( ; i<n; i++) {
            a[i] += a[i+1];
        }
        for(i=j-1; i<=n; i++) {
            cout << a[i] << " ";
        }
        cout << endl;
    }

}

int main() {

    int n;

    cout << "Enter number of rows: ";
    cin >> n;

    printPascalTriangle(n);

}