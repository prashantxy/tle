#include<bits/stdc++.h>

using namespace std;


void solve(){
int n;
cin>>n;
vector<int>arr(n);
vector<int>arr1(n);
set<int>st;
set<int>st1;
for(int i = 0;i<n;i++){
    cin>>arr[i];
    st.insert(arr[i]);
}
for(int i = 0;i<n;i++){
    cin>>arr1[i];
     st1.insert(arr1[i]);
}
if(st1.size()==2&&st.size()==2){
    cout<<"YES"<<endl;
}
else if(st1.size()==1&&st.size()==1){
    cout<<"NO"<<endl;
}
else if((st1.size()==1&&st.size()==2)||(st1.size()==2&&st.size()==1)){
    cout<<"NO"<<endl;
}
else{
    cout<<"YES"<<endl;
}
}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}