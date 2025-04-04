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


template <typename T>
void print(T &&t) { cout << t << "\n"; }
void printarr(ll arr[], ll n) {
    fl(i, n) cout << arr[i] << " ";
    cout << "\n";
}
template <typename T>
void printvec(vector<T> v) {
    ll n = v.size();
    fl(i, n) cout << v[i] << " ";
    cout << "\n";
}
template <typename T>
ll sumvec(vector<T> v) {
    ll n = v.size();
    ll s = 0;
    fl(i, n) s += v[i];
    return s;
}


#define int long long
vector<int> vec;
map<int, int> dp[121];

int func(int x, int k) {
    if (k == 0) return 1;
    if (x == 0 || k < 0) return 0;
    if (x < 5) return (k <= x);
    if (dp[k].find(x) != dp[k].end()) return dp[k][x];

    int y = *prev(upper_bound(vec.begin(), vec.end(), x));
    int ans = func(y - 1, k) + func(x - y, k - 1);

    return dp[k][x] = ans;
}

void precomputeVec() {
    vec.clear();
    vec.push_back(1);
    for (int i = 1; i <= 100; ++i) {
        vec.push_back(vec.back() + vec[vec.size() - 1]);
        if (vec.back() > 1e9) break;
    }
}

void solve() {
    int l, r, k;
    cin >> l >> r >> k;

    if (k > 120) {
        cout << "0\n";
        return;
    }

    int ans = func(r, k) - func(l - 1, k);
    cout << ans << '\n';
}

// Main
int32_t main() {
    Code By pdubey1924_macro

    precomputeVec(); 
    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
