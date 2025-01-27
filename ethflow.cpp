#include <bits/stdc++.h>
using namespace std;

void solve() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        vector<int> arr1(n);

        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        int m = n;
        for (int i = 0; i <= n / 2; i++) {
            m--;
            int ans = 2 * m + 1;
            arr1[i] = ans;
        }
        
        int j = n / 2;
        for (int i = n / 2 + 1; i < n; i++) {
            arr1[i] = arr1[j];
            j--;
        }

        bool ans1 = true;
        for (int i = 0; i < n; i++) {
            if (arr[i] < arr1[i]) {
                ans1 = false;
                break; 
            }
        }

        if (ans1) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
