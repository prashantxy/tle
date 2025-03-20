#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--){
        int n;
        ll x;
        cin >> n >> x;
        vector<ll> a(n);
        for (int i = 0; i < n; i++){
            cin >> a[i];
        }
        sort(a.begin(), a.end());
 
        vector<ll> prefix(n + 1, 0);
        for (int i = 0; i < n; i++){
            prefix[i + 1] = prefix[i] + a[i];
        }
        
        ll low = 1, high = 1000000000000000000LL, ans = 1;
        while(low <= high){
            ll mid = (low + high) / 2;
          
            int idx = lower_bound(a.begin(), a.end(), mid) - a.begin();
           
            bool ok = false;
            if(idx == 0){
              
                ok = true;
            } else {
              
                if(mid <= (x + prefix[idx]) / idx)
                    ok = true;
            }
            
            if(ok){
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1; 
            }
        }
        cout << ans << "\n";
    }
    return 0;
}
