
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

int getLength(node *head, node *&last) {

    node *tmp = head;
    int cnt = 0;
    while(tmp) {
        if(tmp -> next == NULL) {
            last = tmp;
        }
        cnt++;
        tmp = tmp -> next;
    }
    return cnt;

}

node* getKthNodeBack(node *head, int n, int k) {
    int p = n-k+1;
    p--;
    while(p) {
        head = head -> next;
        p--;
    }
    return head;
}

node* rotateLinkedListK(node *head, int k) {
    node *last = NULL;
    int len = getLength(head, last);
    if(last == NULL) {
        cout << "LAST IS NULL\n";
    }
    if(len == 0 || len == 1) {
        return NULL;
    }

    k = k % len;
    node *tmp = getKthNodeBack(head, len, k+1);
    last -> next = head;
    head = tmp -> next;
    tmp -> next = NULL;
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
    int k = 1;
    head = createLinkedList();
    printLL(head);

    cout << "Enter number of times to rotate right : ";
    cin >> k;

    node *newHead = rotateLinkedListK(head, k);
    cout << "Rotated ";
    printLL(newHead);

}
