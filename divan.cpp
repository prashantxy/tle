#include <bits/stdc++.h>
using namespace std;

#define fio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using ll = long long;

int main() {
    fio;
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<pair<ll, int>> v(n);

        for (int i = 0; i < n; i++) {
            cin >> v[i].first;
            v[i].second = i; 
        }

       
        sort(v.rbegin(), v.rend());

        ll sum = 0;
        vector<ll> ans(n);
       
        int x = 1;
        for (int i = 0; i < n; i++) {
            ll value = v[i].first;
            int index = v[i].second;
            
            sum += 2LL * x * value;  
            
            ans[index] = (i & 1) ? x : -x;
            if (i & 1) x++; 
        }

        cout << sum << '\n';
        cout << 0 << ' ';  // Center position
        for (int i = 0; i < n; i++)
            cout << ans[i] << " \n"[i == n - 1];
    }
    return 0;
}
