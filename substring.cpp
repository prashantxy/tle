#include<bits/stdc++.h>

using namespace std;


void solve(){
    int t;
    cin>>t;
string s;
cin>>s;
for(int i = 1;i<t;i++){
    if(s[i]<s[i-1]){
      cout<<"YES"<<endl;
    cout<<i<<" "<<i+1<<endl;
   return;
    }
}
cout<<"NO"<<endl;

}

int main(){
   
        solve();
    
    return 0;
}