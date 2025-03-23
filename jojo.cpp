#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int getMaxCircularOnes(const string &s) {
    int n = s.size();
    int L = 0, curr = 0;
   
    for (int i = 0; i < n; i++){
        if(s[i] == '1'){
            curr++;
            L = max(L, curr);
        } else {
            curr = 0;
        }
    }
 
    int prefix = 0;
    for (int i = 0; i < n && s[i] == '1'; i++){
        prefix++;
    }
  
    int suffix = 0;
    for (int i = n - 1; i >= 0 && s[i] == '1'; i--){
        suffix++;
    }
    L = max(L, prefix + suffix);
    return L;
}
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        int n = s.size();
       
        bool allOnes = true;
        for (char c : s) {
            if(c == '0'){
                allOnes = false;
                break;
            }
        }
        if(allOnes){
            cout << (long long)n * n << "\n";
            continue;
        }
        
        int L = getMaxCircularOnes(s);
        long long ans = 0;  
        
        for (int h = 1; h <= L; h++){
            int width = L - h + 1;
            long long area = (long long)h * width;
            ans = max(ans, area);
        }
        
        cout << ans << "\n";
    }
    
    return 0;
}
