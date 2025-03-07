#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, k;
    cin >> n >> k;
    
   
    vector<vector<int>> perms(k, vector<int>(n));
    for (int p = 0; p < k; p++){
        for (int i = 0; i < n; i++){
            cin >> perms[p][i];
        }
    }
 
    vector<vector<int>> pos(k, vector<int>(n + 1));
    for (int p = 0; p < k; p++){
        for (int i = 0; i < n; i++){
            int num = perms[p][i];
            pos[p][num] = i;
        }
    }
   
    vector<int> dp(n, 1);
    int ans = 1;
    
    for (int i = 0; i < n; i++){
        for (int j = 0; j < i; j++){
           
            bool canExtend = true;
            for (int p = 1; p < k; p++){
                if (pos[p][perms[0][j]] >= pos[p][perms[0][i]]){
                    canExtend = false;
                    break;
                }
            }
            if (canExtend){
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        ans = max(ans, dp[i]);
    }
    
    cout << ans << "\n";
    return 0;
}
