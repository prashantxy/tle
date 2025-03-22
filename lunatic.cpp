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
        long long a[100005];  
        for (int i = 0; i < n; i++){
            cin >> a[i];
        }
        if(n == 1){
            cout << 0 << "\n";
            continue;
        }
       
        long long g = 0; 
        for (int i = 0; i < n/2; i++){
            long long diff = llabs(a[i] - a[n - 1 - i]);
            g = (i == 0) ? diff : __gcd(g, diff);
        }
       
            cout << g << "\n";
        
    }
    
    return 0;
}
