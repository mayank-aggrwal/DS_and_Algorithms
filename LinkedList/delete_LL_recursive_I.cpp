
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

node* deleteLinkedList(node *head) {

    if(head == NULL) {
        return NULL;
    }

    node *x = head -> next;
    delete head;
    node *tmp = deleteLinkedList(x);
    return tmp;
    
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

    head = deleteLinkedList(head);
    if(head == NULL) {
        cout << "Linked List deleted successfully" << endl;
    }
    else {
        cout << "Linked List not deleted" << endl;
    }

}
