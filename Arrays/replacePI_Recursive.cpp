
#include <iostream>
#include <string.h>
using namespace std;

void replacePI(char arr[]) {

    if(strlen(arr) == 0) {
        return ;
    }

    if((arr[0] == 'p') && (arr[1] == 'i')) {

        // SHIFTING ARRAY BY 2
        int i = strlen(arr) + 2;
        for(; i>=2; i--) {
            arr[i] = arr[i-2];
        }

        // REPLACE PI BY "3.14"
        arr[0] = '3';
        arr[1] = '.';
        arr[2] = '1';
        arr[3] = '4';
    }
    replacePI(arr+1);

}

int main() {

    char inp[100];
    char *s = "pixxpipixpi";
    strcpy(inp, s);
    cout << "Input: " << inp << endl;
    replacePI(inp);

    cout << "Output: " << inp << endl;
}