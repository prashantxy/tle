#include "bits/stdc++.h"
using namespace std;
 //PRASHANT TEMPLATE.
#define ll long long
#define          all(v)              v.begin(), v.end()
#define         rall(v)              v.rbegin(),v.rend()
#define            pb                push_back
#define          sz(a)               (int)a.size()

void solve() {
   int n,m;
   cin>>n>>m;
   vector<int>arr(m+1);
   for(int i = 0+1;i<=m;i++){
    cin>>arr[i];
   }
   sort(arr.begin(),arr.end());
  int j = 1;
  cout<<n-m<<endl;
   for(int i = 1;i<=n;i++){
     if(i==arr[j]){
        j++;
        continue;
     }
        cout<<i<<" ";
   }
   

}   
 
int32_t main() {
   
        solve();
    
}