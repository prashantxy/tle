#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    unordered_map<char, int> color;  
    bool isPossible = true;

    for (int i = 0; i < n; i++) {
        char ch = s[i];
        if (color.count(ch)) {
   
            if (color[ch] != (i % 2)) {
                isPossible = false;
                break;
            }
        } else {
            
            color[ch] = i % 2;
        }
    }

    cout << (isPossible ? "YES" : "NO") << "\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
