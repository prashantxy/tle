#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// #define Prashant 1

// Speed
#define Code ios_base::sync_with_stdio(false);
#define By cin.tie(NULL);
#define pdubey1924_macro cout.tie(NULL);  // Renamed the macro to avoid conflict

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
#define py cout << "YES\n";
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

// Code by Prashant Dubey
// Language C++
// Code

void solve() {
    ll n;
    cin >> n;
    vector<int> a(n);
    fl(i, n) cin >> a[i];
    vector<pair<int,int>> ops;
    auto compute_mex_sub = [&](int l, int r) -> int {
        int curSize = a.size();
        vector<bool> present(curSize + 5, false);
        for (int i = l; i <= r; i++) {
            if(a[i] < (int)present.size())
                present[a[i]] = true;
        }
        int mex = 0;
        while(present[mex]) mex++;
        return mex;
    };

    auto doOp = [&](int l, int r) {
        int L = l - 1, R = r - 1;
        int newVal = compute_mex_sub(L, R);
        vector<int> newA;
        for (int i = 0; i < L; i++)
            newA.pb(a[i]);
        newA.pb(newVal);
        for (int i = R + 1; i < (int)a.size(); i++)
            newA.pb(a[i]);
        a = newA;
        ops.pb({l, r});
    };
    while(a.size() > 1) {
        bool Contain0 = false;
        for (auto x : a) {
            if(x == 0) {
                Contain0 = true;
                break;
            }
        }
        if(Contain0) {
            int idx = -1;
            for (int i = (int)a.size()-1; i >= 0; i--) {
                if(a[i] == 0) { idx = i; break; }
            }
            if(idx == 0) {
                doOp(1, 2);
            } else {
                doOp(idx, idx+1);
            }
        } else {
            doOp(1, a.size());
        }
    }
    
    cout << ops.size() << "\n";
    for (auto &op : ops)
        cout << op.first << " " << op.second << "\n";
}

int main() {
    Code By pdubey1924_macro  
    ll t;
    cin >> t;
    fl(i, t) {
        solve();
    }
    return 0;
}
// End
