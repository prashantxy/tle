#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n,k;
    cin >> n>>k;
    
    vector<int> arr(n);
    for(int i = 0;i<n;i++){
        cin>>arr[i];
    }
    for(int i = 0;i<n;i++){
        if((i&(n-1))==i){
            cout<<k<<" ";
        }
        else{
            cout<<0<<endl;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
     int n;
     int k;
     cin>>n>>k;
     for(int i = 0;i<n;i++){
        if((i&(n-1))==i){
            cout<<k<<" ";
        }
        else{
            cout<<0<<" ";
        }
     }
     cout<<endl;
    }
    return 0;
}
