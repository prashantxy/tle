#include <bits/stdc++.h>
using namespace std;
using lli = long long int;

void solve() {
    lli n;
    cin >> n;
    vector<lli> a(n);
    for (lli i = 0; i < n; ++i) {
        cin >> a[i];
    }
    lli ans = a[0];  
    lli sum = a[0];  
    for(int i = 1; i < n; ++i){
    if((abs(a[i]) % 2) != (abs(a[i - 1]) % 2)){
        sum = max(a[i], sum + a[i]);
        ans = max(ans, sum);
    } else {
        ans = max(ans, sum);
        sum = a[i]; 
    }
}
lli maxi = *max_element(a.begin(),a.end());
ans = max(ans,maxi); 
cout << ans <<endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
