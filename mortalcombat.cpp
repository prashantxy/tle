#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll INF = (ll)1e18;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        vector<ll> A(N);
        for (int i = 0; i < N; i++) 
            cin >> A[i];
            
        vector<array<ll,2>> dp(N+2, {INF, INF});
        dp[0][1] = 0;          

        for (int i = 0; i < N; i++) {
            for (int who = 0; who < 2; who++) {
                if (dp[i][who] == INF) continue;    
             
                for (int take = 1; take <= 2 && i + take <= N; take++) {
                    ll cost = dp[i][who];
                  
                    if (who == 1) {
                        cost += A[i];
                        if (take == 2) 
                            cost += A[i+1];
                    }
                    dp[i+take][who^1] = min(dp[i+take][who^1], cost);
                }
            }
        }

        cout << min(dp[N][0], dp[N][1]) << "\n";
    }
    return 0;
}
