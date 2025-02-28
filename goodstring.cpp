#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    string s;
    cin >> s;

    string res;
    for (char c : s) {
        if (res.empty() || res.back() != c || res.size() % 2 == 0) {
            res += c;
        }
    }

    if (res.size() % 2 == 1) {
        res.pop_back();
    }

    cout << n - res.size() << '\n';
    cout << res << '\n';

    return 0;
}
