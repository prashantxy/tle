#include <bits/stdc++.h>
using namespace std;
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int t;
    cin >> t;
    while(t--){
        long long n, k;
        cin >> n >> k;
 
        long long ans = 0;
        if(n % 2 == 0) {
            ans = (n + k - 2) / (k - 1);
        } else {
            long long remaining = n - k; 
            long long extra = 0;
            if(remaining > 0)
                extra = (remaining + (k - 1) - 1) / (k - 1); 
            ans = 1 + extra;
        }
 
        cout << ans << "\n";
    }
    return 0;
}
