#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while(t--){
       int n,x;
       cin>>n>>x;
       vector<int>arr(n);
       long long sum = 0;
       for(int i = 0;i<n;i++){
        cin>>arr[i];
        sum+=arr[i];
       }
       if(sum == 1LL * x * n){
        cout << "YES" << endl;
       }
      else{
        cout << "NO" << endl;
       }
    }
    return 0;
}
