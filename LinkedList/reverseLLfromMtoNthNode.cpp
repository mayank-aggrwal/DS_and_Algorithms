
#include <iostream>
using namespace std;

class node{
    public:
    int data;
    node *next;
    node(int data) {
        this -> data = data;
        this -> next = NULL;
    }
};

node* createLinkedList() {
    node *head = NULL, *last;
    for(int i = 1; i < 12; i++) {
        node *np = new node(i);
        if (head == NULL) {
            head = np;
            last = np;
        }
        else {
            last -> next = np;
            last = np;
        }
    }
    return head;
}

node* reverseLinkedListMN(node *head, int m, int n) {
    if(m > n) {
        m = m^n;
        n = m^n;
        m = m^n;
    }
    else if(m == n) {
        return head;
    }
    int x = n - m;

    node *t1 = head;
    while(m > 2) {
        t1 = t1 -> next;
        m--;
    }
    node *s = t1 -> next;
    if(m == 1) {
        s = head;
    }
    node *e = s;
    
    for(int i=0; i<x; i++) {
        // cout << "HOO" << x << endl;;
        e = e -> next;
    }
    // cout << e -> data << "  &  " << s -> data << endl;
    node *t4 = e -> next;

    node *prev = s, *curr = s -> next;
    while(prev != e) {
        node *pp = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = pp;
    }
    if(m == 1) {
        head = e;
    }
    else {
        t1 -> next = e;
    }
    
    s -> next = t4;
    return head;

}

void printLL(node *head) {
    cout << "LinkedList: ";
    node *tmp = head;
    while (tmp !=  NULL) {
        cout << tmp -> data;
        if(tmp -> next != NULL) {
            cout << " -> ";
        }
        tmp = tmp -> next;
    }
    cout << endl;
}

int main() {
    node *head = NULL;
    head = createLinkedList();
    printLL(head);

    int m = 11, n = 9;
    node *reversedHead = reverseLinkedListMN(head, m, n);
    cout << "REVERSED ";
    printLL(reversedHead);

}
