#include <bits/stdc++.h>
using namespace std;

void solve() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
       vector<int>arr(n);
       for(int i = 0;i<n;i++){
        cin>>arr[i];
       }
       
       int cnt =0;
       for(int i = 0;i+1<n;i++){
        if(arr[i]==0&&arr[i+1]!=0){
            cnt++;
        }
       }
       if(n==1){
        cout<<0<<endl;
       }
       else{
          cout<<cnt<<endl;
       }
      
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
