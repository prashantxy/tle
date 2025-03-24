#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++){
            cin >> a[i];
        }
        vector<long long> freq(32, 0);
        for (int i = 0; i < n; i++){
            int msb = 31 - __builtin_clz(a[i]); 
            freq[msb]++;
        }
        
        long long ans = 0;
        for (int i = 0; i < 32; i++){
            ans += freq[i] * (freq[i] - 1LL) / 2LL;
        }
        
        cout << ans << "\n";
    }
    return 0;
}
