
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class point {
    public:
    int num;
    int arrayNum;
    int index;
    point(int m, int n, int o) {
        num = m;
        arrayNum = n;
        index = o;
    }
};

class compare {
    public:
    bool operator()(point p1, point p2) {
        return p1.num > p2.num;
    }
};

vector<int> mergekSortedArrays(vector<vector<int>> &arr, int k) {

    priority_queue<point, vector<point>, compare> pq;
    for(int i=0; i<k; i++) {
        point p(arr[i][0], i, 0);
        pq.push(p);
    }

    vector<int> ans;

    while(!pq.empty()) {
        point x = pq.top();
        ans.push_back(x.num);
        pq.pop();

        if(x.index < arr[x.arrayNum].size()-1) {
            point np(arr[x.arrayNum][x.index+1], x.arrayNum, x.index+1);
            pq.push(np);
        }
    }

    return ans;

}

int main() {
    
    int k = 5;
    vector<vector<int>> arr{
        {2,6,12},
        {1,9},
        {23,34,90,2000},
        {11,16,24,89},
        {3,5,7}
    };

    for(int i=0; i<k; i++) {
        cout << "Array " << i+1 << ": ";
        for(int j=0; j<arr[i].size(); j++)
            cout << arr[i][j] << " ";
        cout << endl;
    }

    vector<int> ans = mergekSortedArrays(arr, k);
    cout << "Sorted Array: ";
    for(int i=0; i<ans.size(); i++) 
        cout << ans[i] << " ";
    
}