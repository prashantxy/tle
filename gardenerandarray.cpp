#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, x, y;
    cin >> n >> x >> y;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    unordered_map<long long, int> cnt;
    long long ans = 0;

    for (int i = 0; i < n; i++) {
        int xx = a[i] % x;
        int yy = a[i] % y;
        long long key_lookup = (long long)((x - xx + x) % x) * 200005 + yy;
        long long key_insert = (long long)xx * 200005 + yy;

        ans += cnt[key_lookup];
        cnt[key_insert]++;
    }

    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}
