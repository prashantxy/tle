#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
 
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
        sort(a.begin(), a.end());
       
        unordered_map<ll,ll> dp;
        dp[0] = 0;
        for (ll monsters : a) {
            unordered_map<ll,ll> new_dp;
          
            for (auto &entry : dp) {
                ll x = entry.first;
                ll cost = entry.second;
                
                {
                    ll nx = x + monsters;
                    ll ncost = cost + monsters;
                    if (!new_dp.count(nx) || new_dp[nx] > ncost)
                        new_dp[nx] = ncost;
                }
                
                if(monsters >= x && x > 0){
                  
                    ll diff = monsters - x;
                  
                    for (int d = 0; d < 2; d++){
                       
                        ll k = diff / 2;
                        if(d == 1 && k > 0) k--;
                     
                        if (x + k > monsters) continue;
                        if (monsters - k < x + k) continue;
                        
                        ll cost_split = (diff - k) + 1; 
                      
                        ll newCombo = monsters - x - 2 * k; 
                        ll ncost = cost + cost_split;
                        if (!new_dp.count(newCombo) || new_dp[newCombo] > ncost)
                            new_dp[newCombo] = ncost;
                    }
                }
            }
            
            
            unordered_map<ll,ll> filt;
            for(auto &pr : new_dp){
                ll cx = pr.first, cst = pr.second;
                if(filt.find(cx) == filt.end() || filt[cx] > cst)
                    filt[cx] = cst;
            }
            dp = move(filt);
        }
        
        ll ans = LLONG_MAX;
        for(auto &pr : dp)
            ans = min(ans, pr.second);
        cout << ans << "\n";
    }
    return 0;
}
