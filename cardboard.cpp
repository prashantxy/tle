#include <bits/stdc++.h>
using namespace std;

using ll = long long;
// template ki maa ki chutg
bool safeMul(ll a, ll b, ll limit, ll &res) {
  
    if (a == 0 || b == 0) {
        res = 0;
        return false;
    }
    
    if (a > limit / b) {
        return true;
    }
    res = a * b;
    return false;
}
bool check(ll w, ll sum_s, ll sum_sq, ll n, ll c) {
    
    if (sum_sq >= c) return true;
    ll total = sum_sq;
  
    ll term2;
    if (safeMul(4 * w, sum_s, c, term2) || term2 >= c - total) {
        return true;
    }
    total += term2;
    if (total >= c) return true;
    
    ll ww = w * w;  
    ll term3;
    if (safeMul(4, ww, c, term3)) return true;
    if (safeMul(term3, n, c, term3) || term3 >= c - total) {
        return true;
    }
    total += term3;
    return (total >= c);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    
    while(t--){
        int n;
        ll c;
        cin >> n >> c;
        
        vector<ll> s(n);
        ll sum_s = 0, sum_sq = 0;
        for (int i = 0; i < n; i++){
            cin >> s[i];
            sum_s += s[i];
            sum_sq += s[i] * s[i];
        }
        
        ll low = 1, high = 1000000000, ans = -1;
        while(low <= high){
            ll mid = (low + high) / 2;
            if (check(mid, sum_s, sum_sq, n, c)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        
        cout << ans << "\n";
    }
    
    return 0;
}
