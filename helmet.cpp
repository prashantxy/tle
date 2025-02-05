#include "bits/stdc++.h"
using namespace std;

// PRASHANT TEMPLATE
#define ll long long
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define pb push_back
#define sz(a) (int)a.size()

void solve() {
    ll n,  p;
    cin >> n >> p; 

    vector<ll> A(n), B(n);
    for(ll i = 0; i < n; i++) cin >> A[i];
    for(ll i = 0; i < n; i++) cin >> B[i];

    vector<pair<ll, ll>> cost_cap;
    cost_cap.emplace_back(p, n + 1);  // Fix #1

    for(ll i = 0; i < n; i++) {
        cost_cap.emplace_back(B[i], A[i]);  // Fix #3
    }

    sort(all(cost_cap));

    ll total = 1;
    ll cost = p;
    int idx = 0;

    while (total < n && idx < cost_cap.size()) {  // Fix #2
        int left = n - total;
        if (cost_cap[idx].second <= left) {
            total += cost_cap[idx].second;
            cost += cost_cap[idx].first * 1LL * cost_cap[idx].second;
        } else {
            total = n;
            cost += 1LL * left * cost_cap[idx].first; 
        }
        idx++;
    }

    cout << cost << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
