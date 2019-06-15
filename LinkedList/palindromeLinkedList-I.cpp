
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

int i = 0;
bool gotAns = false;
struct Node *x;


// METHOD I - USING THE PROPERTY OF RECURSION TO FIND LINKED LIST IS PALINDROME OR NOT
bool checkP(Node *head) {
    if((i == 0) && head->next != NULL) {
        bool ans = checkP(head->next);
        if(gotAns) {
            return ans;
        }
    }
    
    // IF REACHED LAST NODE , ASSIGN I EQUALS 1
    if(head->next == NULL) {
        i = 1;
    }
    
    // IF MIDDLE POINT CROSSED THEN ITS PALINDROME
    if((head->next == x) || (head == x)) {
        gotAns = true;
        return true;
    }
    
    if(head->data != x->data){
        gotAns = true;
        return false;
    }
    x = x->next;
    return true;
}



bool isPalindrome(Node *head) {
    x = head;
    int ans = checkP(head);
    i = 0;
    gotAns = false;
    return ans;
}


// METHOD II - USING A STACK
bool isPPalindrome(Node *head) {

}

// METHOD III - REVERSING THE LIST