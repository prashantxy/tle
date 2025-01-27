#include<bits/stdc++.h>
using namespace std;

void solve(){
    int t;
    cin>>t;
    while(t--){
        long long  a,b,n;
        cin>>a>>b>>n;
        long long ans = b;
        vector<long long>arr(n);
        for(int i = 0;i<n;i++){
            cin>>arr[i];
            ans += min(a-1,arr[i]);
        }
        
        cout<<ans<<endl;
    }
}
int main(){
    solve();
    return 0;
}