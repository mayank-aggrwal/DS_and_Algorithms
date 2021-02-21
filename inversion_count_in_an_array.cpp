
#include <bits/stdc++.h>
using namemspace std;

long inversionCount(vector<int> &a, int s, int e) {
        if (s >= e) return 0;
        int mid = s + (e - s) / 2;
        long ans = inversionCount(a, s, mid) + inversionCount(a, mid + 1, e);
        
        
        // count inversions
        int i = s, j = mid + 1;
        for (; i <= mid; ++i) {
            while (j <= e && a[j] < a[i]) j++;
            ans += j - mid - 1;
        }
        
        // merge sorted arrays
        vector<int> tmp(e - s + 1);
        i = s; j = mid + 1; int k = 0;
        while (i <= mid && j <= e) {
            if (a[i] < a[j]) {
                tmp[k++] = a[i];
                i++;
            } else {
                tmp[k++] = a[j];
                j++;
            }
        }
        while (i <= mid) {
            tmp[k++] = a[i];
            i++;
        }
        while (j <= e) {
            tmp[k++] = a[j];
            j++;
        }
        for (k = s; k <= e; ++k) {
            a[k] = tmp[k - s];
        }
        return ans;
        
}

int main () {
    int n = 5;
    vector<int> arr = {2, 1, 3, 1, 2};
    cout << "Inversion count: " << inversionCount(arr, 0, n - 1) << endl;
}