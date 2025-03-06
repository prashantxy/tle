#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <limits>
using namespace std;
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<long long> cost(n);
    for (int i = 0; i < n; i++){
        cin >> cost[i];
    }
    
    const string target = "hard";
    const int m = 4; 
    const long long INF = 1e18;
    
   
    vector<vector<long long>> dp(n + 1, vector<long long>(m + 1, INF));
    dp[0][0] = 0;
    
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if(dp[i][j] == INF) continue;
            if(s[i] == target[j]){
               
                dp[i+1][j] = min(dp[i+1][j], dp[i][j] + cost[i]);
                
                if(j < m - 1)
                    dp[i+1][j+1] = min(dp[i+1][j+1], dp[i][j]);
            } else {
               
                dp[i+1][j] = min(dp[i+1][j], dp[i][j]);
            }
        }
    
    }
    long long ans = INF;
    for (int j = 0; j < m; j++){
        ans = min(ans, dp[n][j]);
    }
    
    cout << ans << "\n";
    return 0;
}
