#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
    int t;
    cin >> t;  
   vector<ll>dp(110000);
   vector<ll>cnt(110000);

   vector<ll>arr(t);
   for(ll i = 0;i<t;i++){
    cin>>arr[i];
    cnt[arr[i]]++;
   }
  

   dp[1]=cnt[1];
   for(ll i = 2;i<=100000;i++){
    dp[i]=max(dp[i-1],cnt[i]*i + dp[i-2]);
   }
   cout<<dp[100000]<<endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}
