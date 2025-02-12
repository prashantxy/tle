#include <bits/stdc++.h>
using namespace std;
using ll = long long;

 void solve() {
       ll n;
       cin>>n;
       vector<int>arr(n);
       vector<int>arr1(n);
       set<int>st1;
      
       for(int i = 0;i<n;i++){
        cin>>arr[i];
        st1.insert(arr[i]);
       }
       for(int i = 0;i<n;i++){
        cin>>arr1[i];
        st1.insert(arr1[i]);
       }
       map<int,int>mpp1,mpp2;
       mpp1[arr[0]]=1;
       int cnt = 1;
       for(int i = 1;i<n;i++){
        if(arr[i]==arr[i-1]){
            cnt++;
        }
        else{
            cnt = 1;
        }
        mpp1[arr[i]] = max(mpp2[arr[i]],cnt);
       }
       mpp2[arr1[0]]=1;
       cnt = 1;
       for(int i = 1;i<n;i++){
        if(arr1[i]==arr1[i-1]){
            cnt++;
        }
        else{
            cnt = 1;
        }
        mpp2[arr1[i]]= max(mpp2[arr1[i]],cnt);
       }
       int ans = 1;
       for(auto e:st1){
          ans = max(ans, mpp1[e] + mpp2[e]);
       }
       cout<<ans<<endl;
    }
    
    int main() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
    
        int T;
        cin >> T;
        while (T--) {
            solve();
        }
    
        return 0;
       
}

