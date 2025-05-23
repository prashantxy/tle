#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// #define Prashant 1

// Speed
data##_should_be_removed#define Code ios_base::sync_with_stdio(false);
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

// Debug
#ifdef Prashant
#define debug(x)       \
    cerr << #x << " "; \
    cerr << x << " ";  \
    cerr << endl;
#else
#define debug(x)
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

// Code by Prashant Dubey
// Language C++
// Code

vll primes;
void sieve(ll MAX_N) {
    vector<bool> isPrime(MAX_N + 1, true);
    isPrime[0] = isPrime[1] = false;
    for (ll i = 2; i * i <= MAX_N; i++) {
        if (isPrime[i]) {
            for (ll j = i * i; j <= MAX_N; j += i) {
                isPrime[j] = false;
            }
        }
    }
    for (ll i = 2; i <= MAX_N; i++) {
        if (isPrime[i])
            primes.pb(i);
    }
}

void solve() {
    ll n, m;
    cin >> n >> m;
    vll a2(n - 1);
    cin >> a2;
    vll b(n);
    cin >> b;

    vector<ll> c;
    c.reserve(n);
    c.pb(1);
    for (ll x : a2) c.pb(x);

    sort(vr(c));
    sort(vr(b));

    auto check = [&](int k) {
        int rem = n - k;
        for (int j = 0; j < rem; ++j) {
            if (c[j] >= b[j + k]) return false;
        }
        return true;
    };

    int l = 0, r = n;
    while (l < r) {
        int mid = (l + r) / 2;
        if (check(mid)) r = mid;
        else l = mid + 1;
    }

    print(l);
}

int main() {
    Code By pdubey1924_macro;
    const ll MAX_N = 10000000;
    sieve(MAX_N);

    ll t;
    cin >> t;
    while (t--) solve();
    return 0;
}
