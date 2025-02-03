#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    int cnt = 0;
    int maxi = 0;
   
    
    for(int i = 0;i<s.length()-1;i++){
        if(s[i]=='('&&s[i]==')'){
            i++;
        }
        else{
            cnt++;
        }
    }
    cout<<cnt/2<<endl;
   
}
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}