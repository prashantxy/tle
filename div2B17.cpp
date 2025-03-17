#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define fi first
#define se second
typedef long long ll;
typedef pair<ll, int> pli;
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int t; 
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        vector<ll> a(n);
        REP(i, n) cin >> a[i];
        vector<pli> v;
        REP(i, n) v.pb({a[i], i});
        sort(all(v), [](const pli &p1, const pli &p2){
            return p1.fi > p2.fi;
        });
 
        ll maxVal = v[0].fi;
        int freq = 0;
        for (auto &p : v){
            if(p.fi == maxVal) freq++;
            else break;
        }
 
        ll ans = 0;
        if(freq >= 2){
            ll sumSeeds = 0;
            REP(i, k) sumSeeds += v[i].fi;
            ans = sumSeeds + maxVal;
        }
        else{
            ll sumSeeds = 0;
            FOR(i, 1, k+1) sumSeeds += v[i].fi;
            ans = sumSeeds + maxVal;
        }
 
        cout << ans << "\n";
    }
    return 0;
}
