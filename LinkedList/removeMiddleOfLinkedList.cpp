
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

void removeMidNode(node *head) {
    if(head == NULL || head -> next == NULL) {
        return ;
    }
    node *mid = head, *tmp = head -> next, *prev = NULL;
    while(tmp != NULL && tmp -> next != NULL) {
        prev = mid;
        mid = mid -> next;
        tmp = tmp -> next -> next;
    }
    node *x = prev -> next;
    prev -> next = prev -> next -> next;
    delete(x);
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
    removeMidNode(head);

    cout << "Linked List after removing mid-\n ";
    printLL(head);

}
