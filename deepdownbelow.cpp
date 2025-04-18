#include <iostream>
#include <bits/stdc++.h>
using namespace std;

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

// Code by Prashant Dubey

void solve() {
    ll n;
    cin >> n;
    vector<pair<ll,ll>> caves;
    caves.reserve(n);

    for (ll i = 0; i < n; i++) {
        ll k;
        cin >> k;
        ll r = 0;
        for (ll j = 0; j < k; j++) {
            ll a;
            cin >> a;
            r = max(r, a - j);
        }
        caves.emplace_back(r + 1, k);
    }
    sort(caves.begin(), caves.end());

    ll ans = 0;
    ll cum = 0; 
    for (auto &p : caves) {
        ll req = p.first;
        ll len = p.second;
        ans = max(ans, req - cum);
        cum += len;
    }

    cout << ans << "\n";
}

int main() {
    Code By pdubey1924_macro
    ll t;
    cin >> t;
    while (t--) solve();
    return 0;
}
