#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> digits(n);
    for (int i = 0; i < n; i++) {
        cin >> digits[i];
    }
    int req[10] = {0};
    req[0] = 3; 
    req[1] = 1;
    req[2] = 2;
    req[3] = 1;
    req[5] = 1;
    
    int cnt[10] = {0};
    int ans = 0;
    for (int i = 0; i < n; i++) {
        cnt[digits[i]]++;
        bool possible = true;
        for (int d = 0; d < 10; d++) {
            if (cnt[d] < req[d]) {
                possible = false;
                break;
            }
        }
        if (possible) {
            ans = i + 1; 
            break;
        }
    }
    
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}
