#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
   string s;
   cin>>s;
   if(s[0]!=s.back()){
    s[0]=s.back();
   }
   cout<<s<<endl;
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
