#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        long long a[110];  
        for (int i = 0; i < n; i++){
            cin >> a[i];
        }
        long long g1 = a[0];
        for (int i = 2; i < n; i += 2) {
            g1 = __gcd(g1, a[i]);
        }
        bool patternA = true;
        for (int i = 1; i < n; i += 2) {
            if(a[i] % g1 == 0){
                patternA = false;
                break;
            }
        }
        long long g2 = a[1];
        for (int i = 3; i < n; i += 2) {
            g2 = __gcd(g2, a[i]);
        }
        bool patternB = true;
        for (int i = 0; i < n; i += 2) {
            if(a[i] % g2 == 0){
                patternB = false;
                break;
            }
        }
        
        if(patternA) {
            cout << g1 << "\n";
        } else if(patternB) {
            cout << g2 << "\n";
        } else {
            cout << 0 << "\n";
        }
    }
    
    return 0;
}
