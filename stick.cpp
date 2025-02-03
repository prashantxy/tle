#include<bits/stdc++.h>


// macros

#define ll  long long
using namespace std;
#define nline endl;
void solve(){
    ll x,y,k;
    cin>>x>>y>>k;
    ll ans = 0;
    long double coal = 0;
    long double stick = 0;
    long double div = 0;
    
     coal = y*k;
     stick = coal + (k-1);
    div = ceil(stick/(x-1));
    ans = div + k;
    cout<<ans<<nline; 
}
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}