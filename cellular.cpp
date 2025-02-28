#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int q;
    cin >> q;
    while (q--) {
        int m;
        cin >> m;
        int count = upper_bound(arr.begin(), arr.end(), m) - arr.begin();
        cout << count << "\n";
    }

    return 0;
}
