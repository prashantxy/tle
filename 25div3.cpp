#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, x;
    cin >> n >> x;

    vector<int> result;
    unordered_set<int> used;

    for (int i = 0; i <= x && result.size() < n; i++) {
        result.push_back(i);
        used.insert(i);
    }

  
    int nextNum = x + 1;
    while (result.size() < n) {
        if ((nextNum | x) == x) {  
            result.push_back(nextNum);
            used.insert(nextNum);
        }
        nextNum++;
    }

    for (int num : result) {
        cout << num << " ";
    }
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    
    return 0;
}
