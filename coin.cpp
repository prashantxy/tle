#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> Interval;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while(t--){
       long long int n,k;
       cin>>n>>k;
       long long MOD = k+2;
       if(n<=k || n%MOD == 0){
        cout<<"YES"<<endl;
       }
       else{
        cout<<"NO"<<endl;
       }
    }
    
    return 0;
}
