#include <bits/stdc++.h>
using namespace std;
using ll = long long;

 void solve() {
        ll n;
        cin>>n;
        vector<int>a(n);
        int x,y,z;
        x = y = z = -1 ; 
        for(int i=0; i<n; i++){
            cin>>a[i]; 
        }

        for(int i=1; i<n-1; i++){
            if(a[i-1] < a[i]){
                if(a[i] > a[i+1]){
                    x = i;
                    y = i + 1;
                    z = i + 2;
                    break;
                }
            }
        } 
        if( (x != y && y!= z) && (x != -1)){
            cout<<"YES"<<endl;
            cout<<x<<" "<<y<<" "<<z<<endl;
        } 
        else{
            cout<<"NO"<<endl;
        } 
    }
    int main() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int T;
        cin >> T;
        while (T--) {
            solve();
        }
    
        return 0;
       
}

