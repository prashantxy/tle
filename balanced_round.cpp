#include<bits/stdc++.h>
using namespace std;

void solve(){
    int t;
    cin>>t;
    while(t--){
        long long n,k;
        cin>>n>>k;
        vector<long long>arr(n);
        for(int i = 0;i<n;i++){
            cin>>arr[i];
        }
        sort(arr.begin(),arr.end());
        int cnt = 1,total=0;
        for(int i = 0;i<n-1;i++){
          if((arr[i+1]-arr[i])<=k){
            cnt++;
          }
          else{
            total = max(cnt,total);
            cnt = 1;
          }
        }
        total = max(total,cnt);
        cout<<n-total<<endl;
    }
}
int main(){
    ios::sync_with_stdio(false); 
    cin.tie(0);
    solve();
    return 0;
}