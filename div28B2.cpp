#include <bits/stdc++.h>
using namespace std;
#define ll long long
bool isSq(ll x) { 
    ll s = sqrt(x); 
    return s * s == x;  
}

void solve() {
    int t;
    cin >> t;  
    while (t--) {
        int n;
        cin >> n;  
        ll sum = (ll)n * (n + 1) / 2;
        if (isSq(sum)) {
            cout << -1 << "\n"; 
            continue;
        }
        cout<<2<<" ";
        cout<<1<<" ";
        for(int i = 3;i<=n;i++){
          cout<<i<<" ";
        }
        cout<<endl;
        
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}
