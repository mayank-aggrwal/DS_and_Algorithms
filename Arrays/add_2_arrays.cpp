
#include <iostream>
using namespace std;

void addArrays(int *arr1, int size1, int *arr2, int size2, int *output, int k) {
    int i = size1-1, j = size2-1, carry = 0, sum = 0;
    k--;

    while((i>=0) && (j>=0)) {
        sum = arr1[i] + arr2[j] + carry;
        output[k--] = sum%10;
        carry = sum/10;
        i--;j--;
    }

    while(i >= 0) {
        sum = arr1[i] + carry;
        carry = sum/10;
        output[k--] = sum%10;
        i--;
    }

    while(j >= 0) {
        sum = arr2[j] + carry;
        carry = sum/10;
        output[k--] = sum%10;
        j--;
    }
    if(carry) {
        output[0] = 1;
    }


}

int main() {

    int arr1[] = {1};
    int arr2[] = {9,9,9};

    int size1 = sizeof(arr1)/sizeof(int);
    int size2 = sizeof(arr2)/sizeof(int);

    int k = size1 > size2 ? size1+1 : size2+1;
    int *output = new int[k];
    addArrays(arr1, size1, arr2, size2, output, k);

    for(int i=0; i<k; i++) {
        cout << output[i] << " ";
    }
    cout << endl;

}