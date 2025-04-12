#include <bits/stdc++.h>
using namespace std;

#define Code ios_base::sync_with_stdio(false);
#define By cin.tie(NULL);
#define pdubey1924_macro cout.tie(NULL);

using ll = long long;
using lld = long double;
using ull = unsigned long long;

const lld pi = 3.141592653589793238;
const ll INF = LONG_LONG_MAX;
const ll mod = 1e9 + 7;

typedef pair<ll, ll> pll;
typedef vector<ll> vll;
typedef vector<pll> vpll;
typedef vector<string> vs;
typedef unordered_map<ll, ll> umll;
typedef map<ll, ll> mll;

#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define fl(i, n) for (int i = 0; i < n; i++)
#define rl(i, m, n) for (int i = n; i >= m; i--)
#define vr(v) (v).begin(), (v).end()

#define fore(i, l, r) for (int i = int(l); i < int(r); i++)

typedef pair<int, int> pt;
const int INF_INT = int(1e9);
const int N = 411;

int n, m;
int a[N];
vector< pair<pt, pt> > qs;

inline bool read(){
    if(!(cin >> n >> m))
        return false;
    fore(i, 0, n)
        cin >> a[i];
    qs.resize(m);
    fore(i, 0, m){
        cin >> qs[i].ff.ff >> qs[i].ff.ss >> qs[i].ss.ff >> qs[i].ss.ss;
        qs[i].ff.ff--; qs[i].ff.ss--;
    }
    return true;
}

vector<int> ids[N];
int d[N][N];

inline void solve(){
    fore(i, 0, m)
        ids[qs[i].ff.ff].push_back(i);
    ll ans = -1;
    fore(l, 0, n){
        fore(r, l, n)
            d[0][r] = a[r] - a[l];
        fore(k, 1, n + 1){
            int opt = l;
            fore(r, l, n){
                while(opt < r && max(d[k - 1][opt], a[r] - a[opt]) >= max(d[k - 1][opt + 1], a[r] - a[opt + 1]))
                    opt++;
                d[k][r] = max(d[k - 1][opt], a[r] - a[opt]);
            }
        }
        for (int id : ids[l])
            ans = max(ans, d[qs[id].ss.ss][qs[id].ff.ss] * 1LL * qs[id].ss.ff);
    }
    cout << ans << "\n";
}

int main(){
    Code By pdubey1924_macro
    if(read()){
        solve();
    }
    return 0;
}
