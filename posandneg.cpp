#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
 
typedef long long ll;

const ll NEG_INF = -1e18;
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    
    while(t--){
        int n;
        cin >> n;
        vector<ll> a(n);
        for (int i = 0; i < n; i++){
            cin >> a[i];
        }
        vector<vector<ll>> dp(n + 1, vector<ll>(2, NEG_INF));
        dp[0][0] = 0; 
        for (int i = 0; i < n; i++){
            if (dp[i][0] != NEG_INF) {
                dp[i+1][0] = max(dp[i+1][0], dp[i][0] + a[i]);
                if (i + 1 < n) {
                    dp[i+1][1] = max(dp[i+1][1], dp[i][0] - a[i]);
                }
            }
            if (dp[i][1] != NEG_INF) {
                dp[i+1][0] = max(dp[i+1][0], dp[i][1] - a[i]);
                if (i + 1 < n) {
                    dp[i+1][1] = max(dp[i+1][1], dp[i][1] + a[i]);
                }
            }
        }
        cout << dp[n][0] << "\n";
    }
    
    return 0;
}
