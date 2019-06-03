
#include <iostream>
using namespace std;

int mod(int m, int n) {
    int tmp = m-n;
    return (tmp > 0 ? tmp : -tmp);
}

int minSumToEnd(int *arr, int n, int k, int curr, int *dp) {

    if(curr == n-1) {
        return 0;
    }

    if(dp[curr] != -1) {
        return dp[curr];
    }

    int ans = INT32_MAX;
    for(int i=1; i<=k; i++) {
        int next = curr + i;
        if(next < n) {
            int x = minSumToEnd(arr, n, k, next, dp);
            x += mod(arr[curr], arr[next]);
            if(x < ans) 
                ans = x;
        }
    }
    dp[curr] = ans;
    return ans;

}

int minSumToEnd(int *arr, int n, int k, int curr) {
    int *dp = new int[n];
    for(int i=0; i<n; i++)
        dp[i] = -1;
    return minSumToEnd(arr, n, k, curr, dp);
}

int main() {

    int n = 5, k;
    cin >> n >> k;

    int *arr = new int[n];
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }

    int ans = minSumToEnd(arr, n, k, 0);

    cout << ans << endl;

}
