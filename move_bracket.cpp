#include <bits/stdc++.h>
using namespace std;
void solve(){
    int n;
    cin>>n;
    string s;
    cin>>s;
stack<int>st;
for(auto ch:s){
   if(ch == '('){
    st.push(ch);
   }
   else{
    if(!st.empty()){
        st.pop();
    }
   }
}
cout<<st.size()<<endl;
}
int main() {
    int t;
    cin>>t;
    while(t--){
      solve();
    }
    return 0;
}
