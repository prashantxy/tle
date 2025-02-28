#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int q;
    cin >> q;
    while (q--) {
      long long n;
      cin>>n;
      if(n==1||(n-1)%3==0){
        cout<<"YES"<<endl;
      }
      else{
        cout<<"NO"<<endl;
      }
    }

    return 0;
}
