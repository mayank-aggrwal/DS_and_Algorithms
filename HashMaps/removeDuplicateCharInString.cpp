
#include <iostream>
using namespace std;

void removeDuplicates(char s[]) {

    s[1] = '\0';

}

int main() {

    char str[] = "Maaayyannnnkkk";

    // PRINT ORIGINAL STRING
    cout << "Original String: " << str << endl;

    // REMOVE DUPLICATES
    removeDuplicates(str);

    // PRINT FINAL STRING
    cout << "After removing duplicates: " << str << endl;

}