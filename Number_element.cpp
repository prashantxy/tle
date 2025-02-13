#include <bits/stdc++.h>
using namespace std;
using ll = long long;

 void solve() {
      ll n,m;
      cin>>n>>m;
      ll sum = 0;
      ll negcnt = 0;
      int mini = 1e9;
      vector<vector<int>> arr(n, vector<int>(m));
     for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            cin>>arr[i][j];
            sum+=abs(arr[i][j]);
            if(arr[i][j]<0){
                negcnt++;
            }
            mini = min(abs(arr[i][j]),mini);
        }
     }
     if(negcnt%2==0){
        cout<<sum<<endl;
     }
     else{
        cout<<sum - 2*mini <<endl;
     }
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

