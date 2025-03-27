#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000000007;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> dp(n + 1, 1);
    for (int length = 2; length <= k; ++length) {
        vector<int> new_dp(n + 1, 0);
        for (int j = 1; j <= n; ++j) {
            for (int m = j; m <= n; m += j) {
                new_dp[m] = (new_dp[m] + dp[j]) % MOD;
            }
        }
        
        dp = new_dp;  
    }
    long long answer = 0;
    for (int j = 1; j <= n; ++j) {
        answer = (answer + dp[j]) % MOD;
    }
    
    cout << answer << "\n";
    return 0;
}
