#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
       long long n;
       cin>>n;
       if(n<=2){
        cout<<"NO"<<endl;
       }
        else  if(n&1){
         cout<<"YES"<<endl;
         cout<<(n/2)+1<<endl;
        
       }
       else{
        cout<<"NO"<<endl;
       }
    }
    return 0;
}
