
#include <iostream>
using namespace std;

void printPrimeTill(int n) {
    bool *num = new bool[n+1];
    //SETTING UP ARRAY TO SAVE ALL NUMBERS FROM 1 TO N
    for(int i=0; i<=n; i++) 
        num[i] = true;
    
    for(int i=2; i<=n; i++) {
        if(num[i]) {
            if((long long)i*i > n) {
                break;
            }
            for(int j=i*i; j<=n; j+=i) {
                num[j] = false;
            }
        }
    }
    
    // PRINT THE PRIMES
    for(int i=2; i<=n; i++) {
        if(num[i]) 
            cout << i << " ";
    }
    cout << endl;
}

int main() {

    int n;
    cin >> n;
    
    printPrimeTill(n);

}