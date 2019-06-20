
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

node* reverseEveryK(node *head, int k) {
    
    node *curr = head, *prev = NULL, *mainHead = NULL, *intTail = NULL, *prevprev = NULL;
    int cnt = 0;
    bool leftover = false;

    while(curr != NULL) {
        
        if(cnt == k) {
            
            intTail -> next = curr;
            if(mainHead == NULL) {
                mainHead = prev;
            }
            else {
                prevprev -> next = prev;
            }
            prevprev = prev = intTail;
            cnt = 0;
            leftover = false;
        }
        else if(cnt < k) {
            if(cnt == 0) {
                intTail = curr;
            }
            node *x = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = x;
            cnt++;
            leftover = true;
        }
    }

    if(leftover) {
        intTail -> next = curr;
        if(mainHead == NULL) {
                mainHead = prev;
        }
        else {
                prevprev -> next = prev;
        }
    }

    return mainHead;

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

    node *reversedHead = reverseEveryK(head, k);
    cout << "REVERSED ";
    printLL(reversedHead);

}
