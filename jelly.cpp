#include<bits/stdc++.h>
using namespace std;

void solve(){
int t;
cin>>t;
while(t--){
int a,b,n;
cin>>a>>b>>n;
vector<int>arr(n);
for(int i = 0;i<n;i++){
    cin>>arr[i];
}
int initial = b;
int threshold = a;
int final_answer = initial;
int ans = initial;
sort(arr.begin(),arr.end());
int cnt = 0;
for(int i = 0;i<n;i++){
    final_answer +=arr[i];
    if(final_answer >= threshold){
        ans+=threshold;
        cnt++;
        final_answer = abs(final_answer-threshold);
    }    
}
cout<<ans-cnt<<endl;
}
}
int main(){
solve();
return 0;
}