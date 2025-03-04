#include <iostream>
#include <vector>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> b(n);
        for (int i = 0; i < n; i++){
            cin >> b[i];
        }
        vector<bool> dp(n + 1, false);
        dp[0] = true;
        vector<vector<int>> type2Mapping(n + 1);
        for (int j = 0; j < n; j++){
            int startIndex = j - b[j]; 
            if(startIndex >= 0)
                type2Mapping[startIndex].push_back(j);
        }
        for (int i = 0; i <= n; i++){
            if (!dp[i])
                continue;
            if(i < n) {
                int L = b[i]; 
                if(i + 1 + L <= n)
                    dp[i + 1 + L] = true;
            }
            for (int j : type2Mapping[i]) {        
                dp[j + 1] = true;
            }
        }
        
        cout << (dp[n] ? "YES" : "NO") << "\n";
    }
    return 0;
}
