#include <bits/stdc++.h>
using namespace std;
void solve(){
   int n;
   cin>>n;
   vector<int>arr(n);
   vector<int>arr1(n);
   map<int,int>mpp;
   for(int i = 0;i<n;i++){
    cin>>arr[i];
    mpp[arr[i]]++;
   }
    for(int i = 0;i<n;i++){
    cin>>arr1[i];
    mpp[arr1[i]]++;
   }
   int maxi = INT_MIN;
   for(auto it:mpp){
    maxi = max(maxi,it.second);
   }
   cout<<maxi<<endl;
}
int main() {
   int t;
   cin>>t;
   while(t--){
     solve();
   }
    return 0;
}
