#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve() {
    int n, k;
    cin >> n >> k;

    vector<ll> a(n);
    vector<ll> b(n);

    for (int i = 0; i < n; ++i)
        cin >> a[i];

    for (int i = 0; i < n; ++i)
        cin >> b[i];

    ll total = 0;           
    ll ans = 0;             
    ll max_b = 0;           

 
    for (int i = 0; i < n && i < k; ++i) {
        total += a[i];           
        max_b = max(max_b, b[i]); 
        
        ll remaining = k - (i + 1);  
        
        ll current_xp = total + remaining * max_b;
        
        ans = max(ans, current_xp);
    }

    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--)
        solve();

    return 0;
}
