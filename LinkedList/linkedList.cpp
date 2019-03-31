
template<typename T>
class LinkedListNode{
    public:
    T data;
    LinkedListNode *next;
    LinkedListNode(T data) {
        this -> data = data;
        this -> next = NULL;
    }
};

template<typename T>
class LinkedList{
    LinkedListNode<T> *head;
    public:
    LinkedList() {
        head = NULL;
    }

    void insertBeg(T data) {
        LinkedListNode<T> *np = new LinkedListNode<T>(data);
        if(head == NULL) {
            head = np;
            return ;
        }
        np -> next = head;
        head = np;
    }

    void insertEnd(T data) {
        LinkedListNode<T> *np = new LinkedListNode<T>(data);
        if(head == NULL) {
            head = np;
            return ;
        }
        LinkedListNode<T> *tmp = head;
        while(tmp -> next != NULL) {
            tmp = tmp -> next;
        }
        tmp -> next = np;
    }

    void printList() {
        LinkedListNode<T> *tmp = head;
        cout << "HEAD -> ";
        while(tmp != NULL) {
            cout << tmp -> data;
            if(tmp -> next != NULL) {
                cout << " -> ";
            }
        }
        cout << endl;
    }
};