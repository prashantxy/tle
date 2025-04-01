#include <iostream>
#include <string>
#include <set>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        int n = s.size();
        int q;
        cin >> q;
        set<int> occ;
        for (int i = 0; i <= n - 4; i++) {
            if(s.substr(i,4) == "1100"){
                occ.insert(i);
            }
        }
        
        while(q--){
            int idx;
            int v;
            cin >> idx >> v;
            idx--;
         
            if(s[idx] - '0' == v){
              
                cout << (occ.empty() ? "NO" : "YES") << "\n";
                continue;
            }
            s[idx] = char('0' + v);
            int start = max(0, idx - 3);
            int end = min(n - 4, idx);
            for (int pos = start; pos <= end; pos++){
               
                if(occ.count(pos) && s.substr(pos,4) != "1100"){
                    occ.erase(pos);
                }
               
                else if(!occ.count(pos) && s.substr(pos,4) == "1100"){
                    occ.insert(pos);
                }
            }
            
            cout << (occ.empty() ? "NO" : "YES") << "\n";
        }
    }
    return 0;
}
