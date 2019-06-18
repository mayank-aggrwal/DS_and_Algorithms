
#include <iostream>
#include <queue>
using namespace std;

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

void levelOrderPrintNewLine(BTNode *head) {

    if(head == NULL)
        return ;
    queue<BTNode*> q;
    q.push(head);
    q.push(NULL);
    int cnt=0;
    while(!q.empty()) {
        BTNode *tmp = q.front();
        q.pop();

        if(tmp == NULL) {
            if(!q.empty()) {
                cout << endl;
                q.push(NULL);
            }
        }
        else {
            cout << tmp->data << " ";

            if(tmp->left != NULL) {
                q.push(tmp->left);
            }

            if(tmp->right != NULL) {
                q.push(tmp->right);
            }
        }

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


    BTNode *head = constructTree();
    levelOrderPrintNewLine(head);

}