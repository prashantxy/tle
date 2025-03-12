#include<bits/stdc++.h>
using namespace std;
 
int const MOD = 1e9+7;         // prime number will help
int main(){
int t;
cin>>t;
while(t--){
int n,k;
cin>>n>>k;
long long ans = 1;
for(int i = 0;i<k;i++){
     ans=(ans*n)%MOD;
}
cout<<ans<<endl;
}
return 0;
}