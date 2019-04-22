
#include <iostream>
using namespace std;

void matMul(int **a, int **b, int n) {

    int **tmp = new int*[n];
    for(int i=0; i<n; i++) {
        tmp[i] = new int[n];
        for(int j=0; j<n; j++) {
            tmp[i][j] = 0;
        }
    }

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            tmp[i][j] = 0;
            for(int k=0; k<n; k++) {
                tmp[i][j] += a[i][k]*b[k][j];
            }
        }
    }

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            a[i][j] = tmp[i][j];
        }
    }


}

void matrixExponentiation(int **a, int n, int p) {

    // tmp = I
    int **tmp = new int*[n];
    for(int i=0; i<n; i++) {
        tmp[i] = new int[n];
        for(int j=0; j<n; j++) {
            if(i == j)
                tmp[i][j] = 1;
            else
                tmp[i][j] = 0;
        }
            
    }

    while(p) {
        if(p&1) {
            matMul(tmp, a, n);
        }
        p >>= 1;
        matMul(a, a, n);
        
    } 
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            a[i][j] = tmp[i][j];
        }
    }    

}

int nthFibo(int n) {
    int **arr = new int*[2];
    arr[0] = new int[2];
    arr[1] = new int[2];
    arr[0][0] = 0;
    arr[0][1] = 1;
    arr[1][0] = 1;
    arr[1][1] = 1;
    matrixExponentiation(arr, 2, n);
    return arr[1][0];
}

int main() {
    int n;
    cin >> n;

    cout << "Nth fibonacci number is: " << nthFibo(n) << endl;

}