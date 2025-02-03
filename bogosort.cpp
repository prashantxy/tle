#include <bits/stdc++.h>
using namespace std;
void solve(){
   int n;
   cin>>n;
   vector<int>arr(n);
   for(int i = 0;i<n;i++){
    cin>>arr[i];
   }
   sort(arr.begin(),arr.end(),greater<int>());
   for(int i = 0;i<n;i++){
    cout<<arr[i]<<" ";
   }
   cout<<endl;
}
int main() {
   int t;
   cin>>t;
   while(t--){
     solve();
   }
    return 0;
}
