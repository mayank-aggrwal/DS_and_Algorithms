
#include <iostream>
using namespace std;

struct Node {
    int data;
    struct Node *next, *prev;
    Node(int x) {
        data = x;
        next = prev = NULL;
    }
};


// FUNCTION TO FIND THE MIDDLE NODE
struct Node* midNode(struct Node *head) {
    Node *tmp = head->next;
    while((tmp != NULL) && (tmp->next != NULL)) {
        tmp = tmp->next->next;
        head = head->next;
    }
    return head;
}

// Function to merge two DLLs
struct Node *sortDoubly(struct Node *head) {
    
    if(head->next == NULL) {
        return head;
    }
    
	Node *mid = midNode(head);
	Node *head1 = head, *head2 = mid->next;
	mid->next = NULL;
	head2->prev = NULL;
	
	
	head1 = sortDoubly(head1);
	head2 = sortDoubly(head2);
	
	Node *tmp1 = head1, *tmp2 = head2, *newHead = NULL, *newTail = NULL;
	Node *np = NULL;
	while((tmp1 != NULL) && (tmp2 != NULL)) {
	    if(tmp1->data < tmp2->data) {
	        np = tmp1;
	        tmp1 = tmp1->next;
	        if(tmp1 != NULL)
	            tmp1->prev = NULL;
	        np->next = NULL;
	        
	    }
	    else {
	        np = tmp2;
	        tmp2 = tmp2->next;
	        if(tmp2 != NULL)
	            tmp2->prev = NULL;
	        np->next = NULL;
	    }
	    if(newTail == NULL) {
	            newHead = newTail = np;
	    }
	    else {
	            newTail->next = np;
	            np->prev = newTail;
	            newTail = np;
	    }
	}
	if(tmp1 != NULL) {
	    newTail->next = tmp1;
	    tmp1->prev = newTail;
	}
	if(tmp2 != NULL) {
	    newTail->next = tmp2;
	    tmp2->prev = newTail;
	}
	return newHead;
	
	
}