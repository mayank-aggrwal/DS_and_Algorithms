
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
    int val;
    for(int i = 1; i < 12; i++) {
        if(i%3 == 0) {
            val = 4;
        }
        else {
            val = i;
        }
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

int length_LL(node *head) {
    int len = 0;
    node *tmp = head;
    while(tmp != NULL) {
        tmp = tmp -> next;
        len++;
    }
    return len;
}

node* removeLastOccurenceOfK(node *head, int k) {

    node *ansNode = NULL, *tmp = head, *prev = NULL, *prevToAnsNode = NULL;
    bool isPresent = false;
    while(tmp != NULL) {
        if(tmp -> data == k) {
            isPresent = true;
            ansNode = tmp;
            prevToAnsNode = prev;
        }
        prev = tmp;
        tmp = tmp -> next;
    }

    if(isPresent) {
        if(prevToAnsNode == NULL) {
            head = head -> next;
        }
        else {
            prevToAnsNode -> next = prevToAnsNode -> next -> next;
        }
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

    int k = 4;

    node *newHead = removeLastOccurenceOfK(head, k);
    cout << "Removed from ";
    printLL(newHead);

}
