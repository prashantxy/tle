#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
   
    ll x, n;
    cin >> x >> n;

    ll result = x;
    ll sign = (x % 2 ? 1 : -1);

    if (n % 4 == 1) {
        result += sign * n;
    } else if (n % 4 == 2) {
        result -= sign;
    } else if (n % 4 == 3) {
        result -= sign * (n + 1);
    }

    cout << result << '\n';


    
    
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}
