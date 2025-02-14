#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    ll t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        vector<ll> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        vector<ll> temp(n);
        iota(temp.begin(), temp.end(), 1);
        bool flag = true;

        for (int i = 0; i < n; i++) {
            ll cnt = 1;
            while (i + 1 < n && arr[i] == arr[i + 1]) {
                swap(temp[i], temp[i + 1]);
                i++;
                cnt++;
            }
            if (cnt == 1) {
                cout << -1 << endl;
                flag = false;
                break;
            }
        }

        if (flag) {
            for (int i = 0; i < n; i++) {
                cout << temp[i] << " ";
            }
            cout << endl;
        }
    }
}
