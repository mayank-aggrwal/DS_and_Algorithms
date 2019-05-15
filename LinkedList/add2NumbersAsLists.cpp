
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

node* createLinkedList(int n) {
    node *head = NULL;
    while(n) {
        int digit = n % 10;
        node *np = new node(digit);
        np -> next = head;
        head = np;
        n /= 10;
    }
    return head;
}

node* reverseLinkedList(node *head) {
    node *prev = NULL, *curr = head;
    while (curr != NULL) {
        node *x = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = x;
    }
    return prev;
}

node* lastNodeLL(node *head) {
    node *tmp = head;
    while(tmp -> next != NULL) 
        tmp = tmp -> next;
    return tmp;
}

int lenLL(node *head) {
    int cnt = 0;
    node *tmp = head;
    while(tmp) {
        cnt++;
        tmp = tmp -> next;
    }
    return cnt;
}

node* addLinkedLists(node *head1, node *head2) {

    // REVERSE BOTH LINKED LISTS
    node *rHead1 = reverseLinkedList(head1);
    node *rHead2 = reverseLinkedList(head2);

    int len1 = lenLL(rHead1);
    int len2 = lenLL(rHead2);

    if(len2 > len1) {
        swap(len1, len2);
        swap(rHead1, rHead2);
    }

    int carry = 0;
    node *t1 = rHead1, *t2 = rHead2;
    while(t2) {
        int x = t1->data + t2->data + carry;
        carry = x / 10;
        t1->data = x % 10;
        t1 = t1->next;
        t2 = t2->next;
    }

    if(carry) {
        while(carry && (t1 != NULL)) {
                int x = t1->data + carry;
                t1->data = x % 10;
                carry = x / 10;
                t1 = t1->next;
        }
        if(carry) {
            node *np = new node(carry);
            node *last = lastNodeLL(rHead1);
            last -> next = np;
        }
    }

    return reverseLinkedList(rHead1);

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
    node *head1 = NULL, *head2 = NULL;
    int m = 999234, n = 978;

    // CREATE LINKED LISTS FROM THE TWO NUMBERS
    head1 = createLinkedList(m);
    head2 = createLinkedList(n);

    // PRINT FIRST NUMBER
    cout << "Num1: ";
    printLL(head1);

    // PRINT SECOND NUMBER
    cout << "num2: ";
    printLL(head2);
    
    // ADD THE TWO NUMBERS GIVEN AS LINKED LISTS
    node *head3 = addLinkedLists(head1, head2);
    cout << "SUM: ";
    printLL(head3);

}
