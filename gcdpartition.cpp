#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int T = 1;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        long long s = accumulate(a.begin(), a.end(), 0ll), cur = 0;
        long long ans = 1;
        for (int i = 0; i < n - 1; i++) {
            cur += a[i], s -= a[i];
            ans = max(ans, __gcd(s, cur));
        }
        cout << ans << "\n";
    }
}