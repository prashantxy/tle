#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    ll n,i,c1,c2,x;
    
        cin>>n;
        c1=c2=0;
        while (n--)
        {
            cin>>x;
            if(x==0){
                c1++;
            }else if(x==1){
                c2++;
            }
        }
        cout<<(ll)((ll)1<<c1)*c2<<endl;
    
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
