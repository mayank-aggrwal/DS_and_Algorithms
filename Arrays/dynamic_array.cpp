
template<class T>
class dArray {

    T *arr;
    int totalElements;
    int capacity;

    public:

    dArray() {
        arr = NULL;
        totalElements = 0;
        capacity = 0;
    }

    dArray(T *a, int n) {
        arr = new T[n];
        for(int i=0; i<n; i++) 
            arr[i] = a[i];
        totalElements = capacity = n;
    }

    dArray(int freq, T num) {
        arr = new int[freq];
        for(int i=0; i<freq; i++)
            arr[i] = num;
        capacity = totalElements = freq;
    }

    dArray(dArray &d) {
        if(d.size() <= 0) {
            capacity = totalElements = 0;
            arr = NULL;
        }
        else {
            arr = new T[d.size()];
            capacity = totalElements = d.size();
            for(int i=0; i<d.size(); i++) 
                arr[i] = d.at(i);
        }
    }   

    bool empty() {
        return totalElements == 0;
    }

    int size() {
        return totalElements;
    }

    void clear() {
        totalElements = 0;
    }

    int pop_back() {
        if(totalElements == 0)
            return NULL;
        return  arr[--totalElements];
    
    }

    void push_back(T element) {

        if(totalElements == capacity) {
            int new_capacity = (capacity == 0 ? 1 : 2*capacity);
            T *newArr = new T[new_capacity];
            for(int i=0; i<capacity; i++) 
                newArr[i] = arr[i];
            
            arr = newArr;
            capacity = new_capacity;
        }
        arr[totalElements++] = element;

    }

    int capcity() {
        return this -> capacity;
    }

    T at(int pos) {
        return ((pos >= 0 && pos < totalElements) ? arr[pos] : NULL);
    }

    T front() {
        return (totalElements > 0 ? arr[0] : NULL);
    }

    T back() {
        return (totalElements > 0 ? arr[totalElements-1] : NULL);
    }

};