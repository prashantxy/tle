#include <bits/stdc++.h>
using namespace std;
void solve(){
 int n;
 cin>>n;
 vector<int>arr(n);

 for(int i = 0;i<n;i++){
    cin>>arr[i];
 }
 int ans = arr[0];                      //sabka check karlo bitwise and...
 for(int i = 1;i<n;i++){
    ans&=arr[i];
 }
 cout<<ans<<endl;
}
int main() {
   int t;
   cin>>t;
   while(t--){
      solve();
   }
    return 0;
}
