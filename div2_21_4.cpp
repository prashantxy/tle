#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vll = vector<ll>;

ll get_median(vll& arr, int start, int end) {
    if (start > end) return LLONG_MAX; 
    vll temp;
    temp.reserve(end - start + 1);
    for (int i = start; i <= end; i++) {
        temp.push_back(arr[i]);
    }
    sort(temp.begin(), temp.end());
    int m = temp.size();
    return temp[(m + 1) / 2 - 1]; 
}

void solve() {
    ll n, k;
    cin >> n >> k;
    vll a(n);
    for (ll &x : a) cin >> x;

    bool found = false;
    for (int l = 0; l < n - 2; l++) { 
        for (int r = l + 1; r < n - 1; r++) { 
       
            ll m1 = get_median(a, 0, l);          
            ll m2 = get_median(a, l + 1, r);      
            ll m3 = get_median(a, r + 1, n - 1);   
            vll medians = {m1, m2, m3};
            sort(medians.begin(), medians.end());
            ll median_of_medians = medians[1]; 
            if (median_of_medians <= k) {
                found = true;
                break;
            }
        }
        if (found) break;
    }

    cout << (found ? "YES\n" : "NO\n");
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