
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
    int val = 9;
    for(int i = 1; i < 9; i++) {
        node *np = new node(val);
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

node* reverseLL(node *head) {

    node *prev = NULL, *curr = head;

    // REPEAT UNTIL CURRENT IS NOT NULL
    while(curr != NULL) {
        node *x = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = x;
    }
    return prev;

}

node* addOneToLL(node *head) {

    int carry = (head->data + 1) / 10;
    head -> data = (head->data + 1) % 10;

    node *curr = head -> next, *last = head;

    // IF CARRY ADD TO THE NEXT DIGIT UNTIL THERE IS NO CARRY OR WE REACH END OF LIST
    while(carry && (curr != NULL)) {
        carry = (curr->data + 1) / 10;
        curr -> data = (curr->data + 1) % 10;
        last = curr;
        curr = curr -> next;
    }
    
    // IF CARRY AND LIST IS FINISHED I.E. NUMBER DIGITS BECOME GREATER THAN NODES
    // ADD NEW NODE AT THE END OF LINKED LIST
    if(carry) {
        last -> next = new node(1);
    }

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
    
    // REVERSE LINKED LIST
    head = reverseLL(head);

    // ADD ONE TO REVERSED LIST
    head = addOneToLL(head);

    // REVERSE LIST AGAIN
    head = reverseLL(head);

    cout << "Linked List after adding 1 -\n";
    printLL(head);

}
