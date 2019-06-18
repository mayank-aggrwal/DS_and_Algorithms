
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
    return head;
}

void levelOrderPrint(BTNode *head) {

    if(head == NULL)
        return ;
    queue<BTNode*> q;
    q.push(head);

    while(!q.empty()) {
        BTNode *tmp = q.front();
        q.pop();
        cout << tmp->data << " ";

        if(tmp->left != NULL) {
            q.push(tmp->left);
        }

        if(tmp->right != NULL) {
            q.push(tmp->right);
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

    */


    BTNode *head = constructTree();
    levelOrderPrint(head);

}