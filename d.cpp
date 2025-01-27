#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
       int n,k;
       cin>>n>>k;
       string s;
       cin>>s;
       unordered_map<int ,int>mpp;
       for(int i = 0;i<s.length();i++){
        mpp[s[i]]++;
       }
     int cnt = 0;
       for(auto it: mpp){
       if(it.second%2!=0){
        cnt++;
       }
       }
       cnt-=1;
       if(k<cnt&&s.length()>1){
        cout<<"NO"<<endl;
       }
       else{
        cout<<"YES"<<endl;
       }
    }
    return 0;
}