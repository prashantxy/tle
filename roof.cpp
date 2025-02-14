#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
    int t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        n--;
        ll x = log2(n);
        x = powl(2,x);
        while(n>=x){
            cout<<n--<<" ";
        }
        cout<<0<<" ";
        while(n){
            cout<<n--<<" ";
        }
        cout<<endl;
    }
}
