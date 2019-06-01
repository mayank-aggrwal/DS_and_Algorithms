
template<class T>
class pQueue {

    vector<T> arr;

    public:

    void push(T element) {
        arr.push_back(element);
        int index = arr.size()-1;
        while(index > 0) {
            int parentIndex = (index-1)/2;
            if(arr[parentIndex] < arr[index]) {
                T tmp = arr[parentIndex];
                arr[parentIndex] = arr[index];
                arr[index] = arr[parentIndex];
                index = parentIndex;
            }
            else
                break;
        }
    }

    void pop() {
        if(arr.size() == 0) 
            return ;
        arr[0] = arr[arr.size()-1];
        arr.pop_back();

        int parentIndex = 0;
        while(1) {
            int leftChildIndex = 2*parentIndex+1;
            int rightChildIndex = leftChildIndex+1;
            int maxIndex = parentIndex;

            if(leftChildIndex < arr.size() && arr[leftChildIndex] > arr[maxIndex]) 
                maxIndex = leftChildIndex;

            if(rightChildIndex < arr.size() && arr[rightChildIndex] > arr[maxIndex]) 
                maxIndex = rightChildIndex;
            
            if(maxIndex == parentIndex)
                break;
            
            T tmp = arr[parentIndex];
            arr[parentIndex] = arr[maxIndex];
            arr[maxIndex] = tmp;
            parentIndex = maxIndex;
        }

    }

    T top() {
        return arr[0];
    }

    int size() {
        return arr.size();
    }

    bool empty() {
        return (arr.size() == 0);
    }

    void printPQ() {
        cout << "PQ: ";
        for(int i=0; i<arr.size(); i++) 
            cout << arr[i] << " ";
        cout << endl;
    }

};