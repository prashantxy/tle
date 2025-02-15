#include <bits/stdc++.h>
using namespace std;
using lli = long long int;

void solve() {
    lli n;
    cin >> n;
    vector<lli> a(n);
    
  
    for (lli i = 0; i < n; ++i) {
        cin >> a[i];
        if (i > 0) a[i] += a[i - 1]; 
    }

    lli ans = 0;

 
    for (lli i = 1; i * i <= n; ++i) {
        if (n % i == 0) {  
  
            lli mn = LLONG_MAX, mx = LLONG_MIN;
            for (lli j = i; j <= n; j += i) {
                lli sum = (j == i) ? a[j - 1] : a[j - 1] - a[j - i - 1];
                mn = min(mn, sum);
                mx = max(mx, sum);
            }
            ans = max(ans, abs(mx - mn));

           
            if (i != n / i) {
                lli sz = n / i;
                mn = LLONG_MAX, mx = LLONG_MIN;
                for (lli j = sz; j <= n; j += sz) {
                    lli sum = (j == sz) ? a[j - 1] : a[j - 1] - a[j - sz - 1];
                    mn = min(mn, sum);
                    mx = max(mx, sum);
                }
                ans = max(ans, abs(mx - mn));
            }
        }
    }

    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
