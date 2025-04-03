#include <bits/stdc++.h>
using namespace std;
void factorize(int x, map<int, long long>& factors) {
    for (int d = 2; d * d <= x; d++) {
        while (x % d == 0) {
            factors[d]++;
            x /= d;
        }
    }
    if (x > 1) { 
        factors[x]++;
    }
}

void solve() {
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin>>n;
        cout<<2*n<<endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    solve();
    return 0;
}
