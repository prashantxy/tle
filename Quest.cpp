#include <bits/stdc++.h>
using namespace std;
 
typedef long long lli;
 
// Macro for convenience.
#define All(x) (x).begin(), (x).end()
 
// We'll assume vii is a vector of long long integers.
typedef vector<lli> vii;
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while(t--){
        lli n = 0;
        cin >> n; 
        vector<pair<lli, lli>> a(n);
        vii p(n);
        for(lli i = 0; i < n; ++i){
            cin >> a[i].first;
            a[i].second = i;
        }
        sort(All(a));
        p[0] = a[0].first;
        for(lli i = 1; i < n; ++i){
            p[i] = a[i].first + p[i - 1];
        }
        vii ans(n, 0);
        for(lli i = 0; i < n - 1; ++i){
            if(p[i] >= a[i + 1].first){
                ans[i] = 1;
            }
        }
        for(lli i = n - 2; i >= 0; --i){
            if(ans[i]) ans[i] += ans[i + 1];
        }
        for(lli i = 0; i < n; ++i){
            a[i].first = i + ans[i];
        }
        sort(All(a), [](auto x, auto y){
            return x.second < y.second;
        });
        
        for(auto &pr: a){
            cout << pr.first << ' ';
        }
        cout << "\n";
    }
    return 0;
}
