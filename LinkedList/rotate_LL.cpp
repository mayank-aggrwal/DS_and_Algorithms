
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

int length_LL(node *head) {
    int len = 0;
    node *tmp = head;
    while(tmp != NULL) {
        tmp = tmp -> next;
        len++;
    }
    return len;
}

node* rotateLinkedList(node *head, int k) {

    int n = length_LL(head);
    k = k%n;
    if(k == 0)
        return head;
    
    node *tmp = head;
    k--;
    while(k--) {
        tmp = tmp -> next;
    }

    node *newHead = tmp -> next;
    tmp -> next = NULL;
    tmp = newHead;
    while(tmp -> next != NULL) {
        tmp = tmp -> next;
    }
    tmp -> next = head;
    return newHead;
    
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

    int k = 4;

    node *rotatedHead = rotateLinkedList(head, k);
    cout << "ROTATED ";
    printLL(rotatedHead);

}
