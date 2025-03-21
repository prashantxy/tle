#include <iostream>
#include <vector>
#include <string>
#include <limits>
using namespace std;

int main() {
    string s;
    cin >> s;
    int n = s.size();
    
   
    const int ALPHABET = 26;
    const int INF = numeric_limits<int>::max() / 2;
    
    
    vector<vector<int>> dp(n, vector<int>(ALPHABET, INF));
   
    vector<vector<int>> parent(n, vector<int>(ALPHABET, -1));
    
    
    for (int c = 0; c < ALPHABET; c++) {
        dp[0][c] = (s[0] - 'a' == c ? 0 : 1);
    }
    
    
    for (int i = 1; i < n; i++) {
        for (int c = 0; c < ALPHABET; c++) { // current character choice
            for (int prev = 0; prev < ALPHABET; prev++) { // previous character
                if (prev == c) continue; // adjacent characters must be different
                int cost = (s[i] - 'a' == c ? 0 : 1);
                if (dp[i-1][prev] + cost < dp[i][c]) {
                    dp[i][c] = dp[i-1][prev] + cost;
                    parent[i][c] = prev;
                }
            }
        }
    }
    
    int bestCost = INF, lastChar = -1;
    for (int c = 0; c < ALPHABET; c++) {
        if (dp[n-1][c] < bestCost) {
            bestCost = dp[n-1][c];
            lastChar = c;
        }
    }
    
    
    string ans(n, ' ');
    int cur = lastChar;
    for (int i = n - 1; i >= 0; i--) {
        ans[i] = 'a' + cur;
        cur = (i > 0 ? parent[i][cur] : cur);
    }
    
    cout << ans << endl;
    
    return 0;
}
