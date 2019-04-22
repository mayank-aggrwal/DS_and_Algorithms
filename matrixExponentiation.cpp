
#include <iostream>
using namespace std;

// TO MULTIPLY TWO N*N MATRICES A AND B
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
                tmp[i][j] += a[i][k]*a[k][j];
            }
        }
    }

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            a[i][j] = tmp[i][j];
        }
    }

}

void matExp(int **a, int n, int p) {

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

void printMatrix(int **a, int n) {
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) 
            cout << a[i][j] << " ";
        cout << endl;
    }
}

int main() {

    int n = 2;
    int k = 1;

    int **a = new int*[n];
    for(int i=0; i<n; i++) {
        a[i] = new int[n];
        for(int j=0; j<n; j++) 
            a[i][j] = k++;
    }

    printMatrix(a, n);

    int pow = 3;
    matExp(a, n, pow);
    printMatrix(a, n);

}