#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    ll n, k, b, s;
    cin >> n >> k >> b >> s;

    if (s < k * b || s > (k * b + n * (k - 1))) {
        cout << -1 << endl;
        return;
    }

    vector<ll> ans(n, 0);
    ans[0] = k * b;
    s -= k * b;

    for (int i = 0; i < n && s > 0; i++) {
        ll add = min(s, k - 1);
        ans[i] += add;
        s -= add;
    }

    for (ll x : ans) {
        cout << x << " ";
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}
