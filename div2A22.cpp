#include <bits/stdc++.h>
using namespace std;
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        bool allSame = true;
        for (int i = 1; i < n; i++){
            if(s[i] != s[0]){
                allSame = false;
                break;
            }
        }
        string rs = s;
        reverse(rs.begin(), rs.end());
        bool universal = (s < rs);
 
        if(k == 0){
            cout << (universal ? "YES" : "NO") << "\n";
        } else {
            cout << (allSame ? "NO" : "YES") << "\n";
        }
    }
    return 0;
}
