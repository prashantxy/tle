#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<long long> b(2 * n);
    
    long long sumB = 0;
    for (int i = 0; i < 2 * n; i++) {
        cin >> b[i];
        sumB += b[i];
    }

    sort(b.begin(), b.end()); 

    for (int i = 0; i < 2 * n; i++) {
        long long target = sumB - 2 * b[i];  
        if (binary_search(b.begin(), b.begin() + i, target) || 
            binary_search(b.begin() + i + 1, b.end(), target)) {
            cout << target << " "; 
            for (int j = 0; j < 2 * n; j++) {
                if (j != i) cout << b[j] << " ";
            }
            cout << "\n";
            return;
        }
    }
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
