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
        set<int, greater<int>> nums;
        for (int i = 1; i <= n; i++) {
            nums.insert(i);
        }

        ll preSum = 0;
        vector<int> perm;
        bool valid = true;

        for (int i = 0; i < n; i++) {
            bool found = false;
            for (auto it = nums.begin(); it != nums.end(); ++it) {
                int num = *it;
                if (!isSq(preSum + num)) {
                    preSum += num;
                    perm.push_back(num);
                    nums.erase(it);
                    found = true;
                    break;
                }
            }
            if (!found) {
                valid = false;
                break;
            }
        }
        if (!valid) {
            cout << -1 << "\n";
        } else {
            for (int x : perm) {
                cout << x << " ";
            }
            cout << "\n";
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}
