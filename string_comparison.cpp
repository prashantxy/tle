#include <bits/stdc++.h>
using namespace std;

void solve() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;

        int cnt = 1, maxi = 1;
        for (int i = 1; i < n; i++) {
            if ((s[i] == '<' && s[i - 1] == '<') || (s[i] == '>' && s[i - 1] == '>')) {
                cnt++;
            } else {
                cnt = 1; 
            }
            maxi = max(maxi, cnt);
        }
        maxi++;
        cout << maxi << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    solve();
    return 0;
}
