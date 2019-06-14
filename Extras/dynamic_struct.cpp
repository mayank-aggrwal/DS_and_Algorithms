
#include <iostream>
using namespace std;

struct node {
    int data;
    struct node *next;
    node(int x) {
        data = x;
        next = NULL;
    }
};

int main() {
    int n = 8;
    struct node *np = new node(4);
    np->data = 4
    ;np->next = NULL;

}