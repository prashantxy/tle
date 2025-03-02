#include <iostream>
#include <vector>
using namespace std;

const int MOD = 998244353;
 
void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    
    long long dp1 = 0, dp2 = 0, dp3 = 0;
    for (int i = 0; i < n; i++){
        if (a[i] == 1) {
            dp1 = (dp1 + 1) % MOD;
        } else if (a[i] == 2) {
            dp2 = (2 * dp2 + dp1) % MOD;
        } else if (a[i] == 3) {
            dp3 = (dp3 + dp2) % MOD;
        }
    }
    
    cout << dp3 % MOD << "\n";
}
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    
    return 0;
}
