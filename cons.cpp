#include <bits/stdc++.h>
#define ll long long;
using namespace std;




     ll n;
     cin>>n;
     int mini = INT_MAX;
     int mini1 = INT_MAX;
     for(int i = 0;i<n;i++){
        ll m;
        cin>>m;
        vector<ll>arr(m);
        for(int i = 0;i<m;i++){
            cin>>arr[i];
            mini = min(mini,arr[i]);
            mini1 = min(mini1,arr[i]!=mini?arr[i]:mini1);
        }
     }
     for(int i = 0;i<n;i++){
        for(int i = 0;i<m;i++){
            mini = min(mini,arr[i]);
        }
     }
}
int main() {
    int t;
    cin>>t;
    while(t--){
        solve();
    }     
    return 0;
}
