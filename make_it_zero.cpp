#include<bits/stdc++.h>
using namespace std;


solve(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int>arr(n);
        for(int i = 0;i<n;i++)
        cin>>arr[i];

        if(n&1){
            cout<<4<<endl;
            cout<<1<<" "<<n-1<<endl;
            cout<<1<<" "<<n-1<<endl;
            cout<<n-1<<" "<<n<<endl;
            cout<<n-1<<" "<<n<<endl;
        }
        else{
            cout<<2<<endl;
            cout<<1<<" "<<n<<endl;   //intuition yeah hai ki even per hum multiple operations kar sakte hai
            
            cout<<1<<" "<<n<<endl;
        }
    }
}
int main(){
    solve();
    return 0;
}