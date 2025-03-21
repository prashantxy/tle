#include <bits/stdc++.h>
using namespace std;
 
const long long MOD = 1000000007;
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;

    long long inv6 = 166666668;
    
    while(t--){
        long long n;
        cin >> n;
        long long m = n - 1;  
       
        long long m2 = (m * m) % MOD;
 
        long long term = ( (4 * m2) % MOD + (15 * m) % MOD + 17 ) % MOD;
       
        long long numerator = (m * term) % MOD;
     
        long long S = (1 + (numerator * inv6) % MOD) % MOD;
        
        long long ans = (2022 % MOD * S) % MOD;
        
        cout << ans << "\n";
    }
    
    return 0;
}
