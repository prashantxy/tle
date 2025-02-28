
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

   int n,a,b,c;
   string s;
   cin>>n>>a>>b>>c;
   cin>>s;
   vector<int>arr;
   int cnt = 0;
   for(int i = 0;i<s.length();i++){
        if(s[i]=='0'){
            cnt++;
        }
        else{
            cnt = 0;
        }
        if(cnt==b){
            cnt = 0;
            arr.push_back(i+1);
        }
   }
   cout<<max(0,(int)arr.size()-a+1)<<endl;
   for(int i = 0;i<arr.size()-a+1;i++){
    cout<<arr[i]<<" ";
   }
    return 0;
}
