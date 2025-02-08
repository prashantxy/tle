#include <bits/stdc++.h>
#define ll long long int
#define nline '\n'
using namespace std;

void solve()
{
   
    vector<ll>arr(3);
    for(int i = 0;i<3;i++){
        cin>>arr[i];
    }
   
    if(arr[2]==arr[0]+arr[1]){
        cout<<"+"<<endl;
    }
    else{
        cout<<"-"<<endl;
    }

   

     

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll T = 1;
    cin >> T;
    while (T--) 
    { 
           solve();
           
    }

}