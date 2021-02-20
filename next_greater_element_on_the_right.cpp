
#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;

vector<int> nextGreaterElementRight(vector<int> &nums) {
    int n = nums.size();
    vector<int> nge(n, -1);
    stack<int> s;

    for (int i = n - 1; i >= 0; --i) {
        while (!s.empty() && nums[s.top()] < nums[i]) {
            s.pop();
        }
        
        if (s.empty()) nge[i] = -1;
        else nge[i] = s.top();

        s.push(i);
    }

    return nge;
}

int main () {
    int n = 4;
    vector<int> nums = {4, 5, 2, 25};
    vector<int> nge = nextGreaterElementRight(nums);
    for(int i = 0; i < nge.size(); ++i) {
        cout << nge[i] << ", ";
    }
    cout << endl;
    for(int i = 0; i < nge.size(); ++i) {
        if (nge[i] == -1)
            cout << -1 << ", ";
        else cout << nums[nge[i]] << ", ";
    }
    cout << endl;
}