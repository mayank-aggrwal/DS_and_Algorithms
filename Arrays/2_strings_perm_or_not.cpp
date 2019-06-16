
#include <iostream>
#include <string.h>
using namespace std;

bool isPermutation(char str1[], char str2[]) {

    int len1 = strlen(str1);
    int len2 = strlen(str2);
    if(len1 != len2) {
        return false;
    }

    int check[26] = {0};
    for(int i=0; i<len1; i++) {
        check[str1[i]-97]++;
    }

    for(int i=0; i<len2; i++) {
        int freq = check[str2[i]-97];
        if(freq == 0) {
            return false;
        }
        else if(freq > 0) {
            check[str2[i]-97]--;
        }
    }
    return true;

}

int main() {

    char str1[100] = "abcde";
    char str2[100] = "dbceh";
    
    cout << str1 << endl << str2 << endl;
    if(isPermutation(str1, str2)) {
        cout << "permutation" << endl;
    }
    else {
        cout << "not permutation" << endl;
    }
}