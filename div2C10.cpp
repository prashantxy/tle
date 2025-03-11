#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        n*=2;
        vector<int> a(n);
        vector<int> b,c;
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        sort(a.rbegin(),a.rend());
        long long last=a[0];
        cout<<a[0]<<" ";
        for(int i=1;i<n/2;i++){
            cout<<a[n-i]<<" "<<a[i]<<" ";
            last+=(a[i]-a[n-i]);
        }
        last+=(a[n/2]);
        cout<<last<<" "<<a[n/2]<<endl;
    }
}