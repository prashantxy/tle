#include <bits/stdc++.h>
using namespace std;
using ll = long long;

 void solve() {
        long long a,b;
        cin >> a >> b;
        if(a==b)
            cout << 0 << " " << 0 << '\n';
        else
        {
            long long g = abs(a-b);
            long long m = min(a%g,g-a%g);
            cout << g << " " << m << '\n';
        }
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

