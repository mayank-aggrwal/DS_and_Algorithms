
#include <iostream>
using namespace std;

void printWaveForm(int **mat, int m,int n) {

    int dir = true;
    for(int j=0; j<n; j++) {
        int s = 0 , e = m, k = 1;
        if(!dir) {
            s = m-1;
            e = -1;
            k = -1;
        }
        for(int i=s; i!=e; i+=k) {
            cout << mat[i][j] << " ";
        }
        dir = dir ^ true;
    }

}

void printMatrix(int **mat, int m, int n) {

    cout << "\nMATRIX: \n";
    for(int i=0; i<m; i++) {
        for(int j=0; j<n; j++) {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }

}

int main() {

    int m,n;

    // INPUT FOR NUMBER OF ROWS AND COLUMNS
    cout << "Enter number of rows: ";
    cin >> m;
    cout << "Enter number of columns: ";
    cin >> n;

    int val = 0;

    // FORM MATRIX DYNAMICALLY
    int **mat = new int*[m];
    for(int i=0; i<m; i++) {
        mat[i] = new int[n];
        for(int j=0; j<n; j++) 
            mat[i][j] = val++;
    }

    // PRINT THE MATRIX
    printMatrix(mat, m, n);

    // PRINT MATRIX IN WAVE FORM
    cout << "\nWave Print: ";
    printWaveForm(mat, m, n);

}