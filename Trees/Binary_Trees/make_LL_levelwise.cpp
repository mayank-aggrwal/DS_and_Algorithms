
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class node {
    public:
    int data;
    node *next;
    node(int data) {
        this->data = data;
        next = NULL;
    }
};

class BTNode {
    public:
    int data;
    BTNode *left, *right;
    BTNode(int data) {
        this->data = data;
        left = right = NULL;
    }
};

BTNode* constructTree() {
    BTNode *head = NULL;
    head = new BTNode(8);
    head->left = new BTNode(6);
    head->right = new BTNode(7);
    head->left->left = new BTNode(9);
    head->right->left = new BTNode(10);
    head->right->right = new BTNode(11);
    head->right->right->right = new BTNode(99);
    return head;
}

vector<node*> makeLL_levelwise(BTNode *root) {

    vector<node*> ans;
    if(root == NULL)
        return ans;

    queue<BTNode*> q;
    
    node *head = NULL, *last = NULL;

    q.push(root);
    q.push(NULL);

    while(!q.empty()) {
        BTNode *tmp = q.front();
        q.pop();

        if(tmp == NULL) {
            ans.push_back(head);
            if(!q.empty()) {
                q.push(NULL);
                head = last = NULL;
            }
            
        }
        else {
            node *np = new node(tmp->data);
            if(head == NULL) {
                head = last = np;
            }
            else {
                last->next = np;
                last = np;
            }
            if(tmp->left != NULL) {
                q.push(tmp->left);
            }

            if(tmp->right != NULL) {
                q.push(tmp->right);
            }
        }

    }

    return ans;

}

void printLL(node *head) {

    node *tmp = head;
    if(tmp==NULL) {
        cout << "NULL";
    }
    while(tmp != NULL) {
        cout << tmp->data << " ";
        tmp = tmp->next;
    }
    cout << endl;

}


int main() {


    /*

                    8
                   /  \
                  6    7
                 /    / \
                9    10  11
                           \
                            99

    */


    BTNode *root = constructTree();
    vector<node*> ans = makeLL_levelwise(root);
    
    for(int i=0; i<ans.size(); i++) {
        printLL(ans[i]);
    }

}