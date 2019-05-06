
// Count no. of substrings of length k whose ASCII value of characters is divisible by k

#include <iostream>
using namespace std;

int slidingCountSubS(char *arr, int n, int k) {

    int sum = 0, count = 0;
    for(int i=0; i<k; i++) {
        sum += arr[i];
    }
    
    if(sum%k == 0)
        count++;
    for(int i=k; i<n; i++) {
        sum += arr[i] - arr[i-k];
        if(sum%k == 0)
            count++;
    }
    return count;

}


int main() {

    char arr[] = "GoodMorning";
    int k = 3;
    int n = sizeof(arr)/sizeof(char);
    cout << "WORD: " << arr << endl;

    cout << "SLIDING WINDOW Count of substrings of length k : ";
    int count = slidingCountSubS(arr, n, k);
    cout << count << endl;

}