#include <bits/stdc++.h>
using namespace std;
void solve(){
    int t;
    cin>>t;
 while(t--)
    {
        long long n,mn,mx;
        cin>>n;
        if(n%2==1 || n<4) cout<<-1<<endl;
        else
        {
            mn = n/6;
            if(n%6!=0) mn++;
            
            mx = n/4;

            cout<<mn<<" "<<mx<<endl;
        }
    }
}
int main() {
  
    solve();

    return 0;
}
