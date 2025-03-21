#include <bits/stdc++.h>
using namespace std;
  
using ll = long long;
  
ll manhattan(ll x1, ll y1, ll x2, ll y2) {
    return abs(x1 - x2) + abs(y1 - y2);
}
  
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    
    while(t--){
        int n, k, a, b;
        cin >> n >> k >> a >> b;
        a--; b--;
        
        vector<ll> x(n), y(n);
        for (int i = 0; i < n; i++){
            cin >> x[i] >> y[i];
        }
        
        ll direct_cost = manhattan(x[a], y[a], x[b], y[b]);
        
        if(k == 0){
            cout << direct_cost << "\n";
            continue;
        }
        
        ll costA = (a < k) ? 0 : (ll)1e18;
        if(a >= k){
            for (int i = 0; i < k; i++){
                costA = min(costA, manhattan(x[a], y[a], x[i], y[i]));
            }
        }
        
        ll costB = (b < k) ? 0 : (ll)1e18;
        if(b >= k){
            for (int i = 0; i < k; i++){
                costB = min(costB, manhattan(x[b], y[b], x[i], y[i]));
            }
        }
        
        ll via_major = costA + costB;
        
        cout << min(direct_cost, via_major) << "\n";
    }
    
    return 0;
}
