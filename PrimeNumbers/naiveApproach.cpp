
#include <iostream>
using namespace std;

void printPrimeTill(int n) {
    for(int i=2; i<=n ;i++) {
        int j = 2;
        for(; j<=i/2; j++) {
            if(i%j == 0) 
                break;
        }   
        if(j > i/2)
            cout << i << " ";
    }
    cout << endl;
}

int main() {

    int n;
    cin >> n;
    
    printPrimeTill(n);

}