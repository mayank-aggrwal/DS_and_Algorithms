
#include <iostream>
#include <unordered_map>
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
    node *x = head;
    int cnt = 0;
    while(cnt < 5) {
        x = x -> next;
        cnt++;
    }
    last -> next = x;
    return head;
}


int removeLoop(node *head) {

    unordered_map<node*, bool> map;
    node *tmp = head, *prev;
    while(tmp != NULL) {
        if(map.count(tmp) == 0) {
            map[tmp] = true;
        }
        else {
            prev -> next = NULL;
            return 1;
        }
        prev = tmp;
        tmp = tmp -> next;
    }
    return 0;

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
    // printLL(head);

    int ans = removeLoop(head);
    if(ans) {
        cout << "Loop was present and was removed" << endl;
    }
    else {
        cout << "Loop is not there" << endl;
    }
    printLL(head);

}
