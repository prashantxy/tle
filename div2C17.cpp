#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for (int i=0; i<(n); ++i)
#define FOR(i,a,b) for (int i=(a); i<(b); ++i)
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define sz(x) ((int)(x).size())
typedef long long ll;

#ifdef DEBUG
    #define dbg(x) cerr << #x << " = " << (x) << "\n";
#else
    #define dbg(x)
#endif

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m; 
        vector<int> cap(m);
        REP(i, m) cin >> cap[i];
        vector<int> F(n+1, 0);
        REP(i, m){
            int c = cap[i];
            if(c > n) c = n;
            F[c]++;
        }
        vector<int> U(n+2, 0);
        U[n+1] = 0;
        for (int x = n; x >= 1; x--){
            U[x] = U[x+1] + F[x];
        }
        
        ll ans = 0;
        FOR(d, 1, n){
            int leftCount = U[d];       // capacity >= d
            int rightCount = U[n-d];    //   capacity >= n-d
            int Mx = max(d, n-d);       
            int same = U[Mx];           
            ll ways = (ll) leftCount * rightCount - same;
            
            if(ways < 0) ways = 0;
            ans += ways;
        }
        
        cout << ans << "\n";
    }
    return 0;
}
