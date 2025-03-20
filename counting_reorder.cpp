#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
 
typedef long long ll;
const ll MOD = 1000000007;
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    
    while(t--){
        int n;
        cin >> n;
        
        vector<ll> a(n), b(n);
        for (int i = 0; i < n; i++){
            cin >> a[i];
        }
        for (int i = 0; i < n; i++){
            cin >> b[i];
        }
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        
        ll ans = 1;

        for (int i = 0; i < n; i++){
            int cnt = n - (upper_bound(a.begin(), a.end(), b[i]) - a.begin());
            ll available = cnt - (n - 1 - i);
            
            if (available <= 0) { 
                ans = 0;
                break;
            }
            
            ans = (ans * available) % MOD;
        }
        
        cout << ans << "\n";
    }
    
    return 0;
}
