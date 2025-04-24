#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// #define Prashant 1

// Speed
#define Code ios_base::sync_with_stdio(false);
#define By cin.tie(NULL);
#define pdubey1924_macro cout.tie(NULL);

// Aliases
using ll = long long;
using lld = long double;
using ull = unsigned long long;

// Constants
const lld pi = 3.141592653589793238;
const ll INF = LONG_LONG_MAX;
const ll mod = 1e9 + 7;

// TypeDEf
typedef pair<ll, ll> pll;
typedef vector<ll> vll;
typedef vector<pll> vpll;
typedef vector<string> vs;
typedef unordered_map<ll, ll> umll;
typedef map<ll, ll> mll;

// Macros
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define fl(i, n) for (int i = 0; i < n; i++)
#define rl(i, m, n) for (int i = n; i >= m; i--)
#define pm cout << "-1\n";
#define pn cout << "NO\n";
#define vr(v) v.begin(), v.end()
#define rv(v) v.end(), v.begin()

// Debug
#ifdef Prashant
#define debug(x)       \
    cerr << #x << " "; \
    cerr << x << " ";  \
    cerr << endl;
#else
#define debug(x) ;
#endif

// Operator overloads
template <typename T1, typename T2>
istream &operator>>(istream &istream, pair<T1, T2> &p) {
    return (istream >> p.first >> p.second);
}
template <typename T>
istream &operator>>(istream &istream, vector<T> &v) {
    for (auto &it : v)
        cin >> it;
    return istream;
}
template <typename T1, typename T2>
ostream &operator<<(ostream &ostream, const pair<T1, T2> &p) {
    return (ostream << p.first << " " << p.second);
}
template <typename T>
ostream &operator<<(ostream &ostream, const vector<T> &c) {
    for (auto &it : c)
        cout << it << " ";
    return ostream;
}

// Utility functions
template <typename T>
void print(T &&t) { cout << t << "\n"; }

struct DSU {
    vector<int> parent, rank;
    DSU(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        iota(parent.begin(), parent.end(), 0);
    }
    int find(int x) {
        return parent[x] == x ? x : parent[x] = find(parent[x]);
    }
    void unionSet(int x, int y) {
        int px = find(x), py = find(y);
        if (px == py) return;
        if (rank[px] < rank[py]) swap(px, py);
        parent[py] = px;
        if (rank[px] == rank[py]) rank[px]++;
    }
};

void solve() {
    ll n;
    string s;
    cin >> n >> s;

    DSU dsu(3 * n);
    vector<ll> w(3 * n, 0);
    vector<int> nodes;
    nodes.reserve(2 * n);

    fl(i, n) {
        if (s[i] == '0') {
            w[i]     = i;          
            w[i + n] = (n - 1) - i; 
            nodes.pb(i);
            nodes.pb(i + n);
        } else {
            w[2 * n + i] = 1;      
            nodes.pb(2 * n + i);
        }
    }

    fl(i, n - 1) {
        if (s[i] == '0' && s[i + 1] == '0') {
            dsu.unionSet(i, i + 1);
            dsu.unionSet(i + n, i + 1 + n);
        }
    }

    fl(i, n) {
        if (s[i] == '1') {
            int di = 2 * n + i;
            if (i - 1 >= 0 && s[i - 1] == '0') {
                dsu.unionSet(di, (i - 1) + n);
            }
            if (i + 1 < n && s[i + 1] == '0') {
                dsu.unionSet(di, (i + 1));
            }
        }
    }

    umll compSum;
    ll ans = 0;
    for (int id : nodes) {
        ll r = dsu.find(id);
        compSum[r] += w[id];
        ans = max(ans, compSum[r]);
    }

    print(ans);
}

int main() {
    Code By pdubey1924_macro

    ll t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
