#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int q;
    cin >> q;
    while (q--) {
       int a,b,c;
       cin>>a>>b>>c;
       int n = a+b+c;
       int l = 0;
       int r = n+1;
       while(l+1<r){
        int mid = (l+r)/2;
        if(mid<=a&&mid<=b&&3*mid<=n){
            l = mid;
        }
        else{
            r = mid;
        }
       }
       cout<<l<<endl;
    }

    return 0;
}
