
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *next, *prev;
    Node(int x) {
        data = x;
        next = prev = NULL;
    }
}

void deleteNode(Node **head_ref, int x) {
    
    Node *head = (*head_ref);
    Node *tmp = head;
    if(head == NULL) 
        return;
    if(x == 1) {
        if(head->next == NULL) {
            *head_ref = NULL;
            return ;
        }
        else {
            head->next->prev = NULL;
            *head_ref = head->next;
            return ;
        }
    }
    
    
    x = x-2;
    while(x--) {
        tmp = tmp->next;
    }
    
    Node *y = tmp->next;
    Node *z = y->next;
    
    tmp->next = z;
    if(z != NULL) {
        z->prev = tmp;
    }
    
    delete y;

}

