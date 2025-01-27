#include <bits/stdc++.h>
using namespace std;

void solve() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        unordered_map<int ,int> seen;
        bool found = false;                     //koi bhi agar 2 aaya toh nahi hoga
                                               //overlaping hai  it increases in 1 2 4 8 ..... 
     vector<int>val(n);
        for (int i = 0; i < n; i++) {
            cin >> val[i];
        }
        for(int i = 0;i<n;i++){
            seen[val[i]]++;
        }
        for(auto it:seen){
            if(it.second>1){
                found = true;
            }
        }
        cout << (found ? "YES" : "NO") << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
