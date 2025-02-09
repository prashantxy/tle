#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n, m;
    cin >> n >> m;

    vector<vector<ll>> arrays(n);
    vector<pair<ll, int>> array_sums(n);   //jiska presum max hoga wahi answer hoga maximum time vo baki mai add hoga

    for (int i = 0; i < n; i++) {
        ll sum = 0;
        vector<ll> a(m);
        for (int j = 0; j < m; j++) {
            cin >> a[j];
            sum += a[j];
        }
        arrays[i] = a;
        array_sums[i] = {sum, i};  
    }

    sort(array_sums.rbegin(), array_sums.rend());

    vector<ll> final_array;
    for (auto &p : array_sums) {
        int idx = p.second;  
        final_array.insert(final_array.end(), arrays[idx].begin(), arrays[idx].end());
    }

    
    ll score = 0, running_sum = 0;
    for (ll num : final_array) {
        running_sum += num;
        score += running_sum;
    }

    cout << score << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while (T--) {
        solve();
    }
}
