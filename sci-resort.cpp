#include <bits/stdc++.h>
#define ll long long int
#define nline '\n'
using namespace std;

void solve()
{
    ll n, k ,q;
    cin >> n >> k >>q;

    vector<int> arr(n);
    ll ans = 0;
    int cnt = 0;

    for (int i = 0; i < n; i++){
        cin >> arr[i];
        if(arr[i]<=q){
            cnt++;
        }                    
        else{                      
            cnt = 0;
        }
        ans += max(0LL,cnt-k+1);
    }
     cout<<ans<<nline;  
        
    
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll T = 1;
    cin >> T;
    while (T--) 
    {
           solve();
          
    }

}