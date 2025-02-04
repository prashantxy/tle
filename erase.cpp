#include "bits/stdc++.h"
using namespace std;
 //PRASHANT TEMPLATE.
#define ll long long
#define          all(v)              v.begin(), v.end()
#define         rall(v)              v.rbegin(),v.rend()
#define            pb                push_back
#define          sz(a)               (int)a.size()

void solve() {
    int n;
    string s;
    cin>>n>>s;
    set<char>st;
    int ans = 0;
    for(int i = 0;i<n;i++){
        st.insert(s[i]);
        ans+=st.size();
    }
    cout<<ans<<endl;
}   
 
int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
}