
#include <iostream>
#include <vector>

using namespace std;

void initVector(vector<int> &num, int n) {

    int tmp = n, cnt = 0;
    while(tmp) {
        tmp = tmp/10;
        cnt++;
    }
    int x = 1;
    for(int i=1; i<cnt; i++) {
        x *= 10;
    }
    while(x) {
        num.push_back(n/x);
        n = n % x;
        x /= 10;
    }

}

void addOne(vector<int> &num) {

    int n = num.size();
    int carry = (num[n-1] + 1) / 10;
    num[n-1] = (num[n-1] + 1) % 10;
    n = n - 2;
    while(carry && n>=0) {
        carry = (num[n] + 1) / 10;
        num[n] = (num[n] + 1) % 10;
        n--;
    }

    if(carry) {
        num.insert(num.begin(),1);
    }

}

int main() {

    vector<int> num;
    int n = 99999;

    // PUSH ALL DIGITS IN THE VECTOR
    initVector(num, n);

    cout << "Number before adding 1: ";
    for(auto i : num) {
        cout << i << " ";
    }
    cout << endl;

    // ADD ONE TO NUMBER REPRESENTED BY VECTOR
    addOne(num);
    
    cout << "Number afterr adding 1: ";
    for(auto i : num) {
        cout << i << " ";
    }
    cout << endl;

}