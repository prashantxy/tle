#include <bits/stdc++.h>
using namespace std;
void solve(){
    string s;
    cin>>s;
    int zero_cnt = 0;
    int one_cnt = 0;
    for(int i = 0;i<s.length();i++){
        if(s[i]=='0'){
            zero_cnt++;
        }
        else{
            one_cnt++;
        }
    }
    int mini = min(zero_cnt,one_cnt);
    if(mini&1){
        cout<<"DA"<<endl;
    }
    else{
        cout<<"NET"<<endl;
    }
}
int main() {
   int t;
   cin>>t;
   while(t--){
     solve();
   }
    return 0;
}
