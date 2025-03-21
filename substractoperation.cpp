#include <bits/stdc++.h>
using namespace std;
  
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while(t--){
        int n;
        long long k;
        cin >> n >> k;
        vector<long long> a(n);
        for (int i = 0; i < n; i++){
            cin >> a[i];
        }
        sort(a.begin(), a.end());
        int i = 0, j = 0;
        bool ok = false;
        while(j < n){
            long long diff = a[j] - a[i];
            if(diff == k){
                ok = true;
                break;
            }
            if(diff < k)
                j++;
            else {
                i++;
                if(i == j)
                    j++;
            }
        }
        cout << (ok ? "YES" : "NO") << "\n";
    }
    return 0;
}
