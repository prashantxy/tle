#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    
    vector<int> arr(n);
    map<int, int> dp;
    int ans = 0, curr = 0;
    
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        dp[arr[i]] = max(dp[arr[i]], dp[arr[i] - 1] + 1);
        
        if (dp[arr[i]] > ans) {
            ans = dp[arr[i]];
            curr = arr[i];
        }
    }
    
    cout << ans << endl;
    vector<int> vec;
    
    for (int i = n - 1; i >= 0; i--) {
        if (arr[i] == curr) {
            vec.push_back(i);
            curr--;
        }
    }
    
    reverse(vec.begin(), vec.end());
    for (int i : vec) {
        cout << i + 1 << " ";
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}
