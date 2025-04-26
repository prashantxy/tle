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
// Use the correct modulus for Kim’s Quest:
const ll mod = 998244353;

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

// Mathematical functions
ll gcd(ll a, ll b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
ll lcm(ll a, ll b) { return (a / gcd(a, b) * b); }
ll moduloMultiplication(ll a, ll b, ll m) {
    ll res = 0;
    a %= m;
    while (b) {
        if (b & 1)
            res = (res + a) % m;
        b >>= 1;
    }
    return res;
}
ll powermod(ll x, ll y, ll p) {
    ll res = 1;
    x %= p;
    if (x == 0) return 0;
    while (y > 0) {
        if (y & 1) res = (res * x) % p;
        y >>= 1;
        x = (x * x) % p;
    }
    return res;
}

// Bits
string decToBinary(int n) {
    string s = "";
    while (n > 0) {
        s = char('0' + (n & 1)) + s;
        n >>= 1;
    }
    return s.empty() ? "0" : s;
}
ll binaryToDecimal(const string &n) {
    ll dec = 0;
    for (char c : n) {
        dec = dec * 2 + (c - '0');
    }
    return dec;
}

// Check
bool isPrime(ll n) {
    if (n <= 1) return false;
    if (n <= 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    for (ll i = 5; i * i <= n; i += 6)
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
    return true;
}
bool isPowerOfTwo(int n) {
    return n > 0 && (n & (n - 1)) == 0;
}
bool isPerfectSquare(ll x) {
    if (x < 0) return false;
    ll r = sqrt(x);
    return r * r == x;
}

void solve() {
    ll n;
    cin >> n;
    vll a(n);
    fl(i, n) {
        cin >> a[i];
        a[i] %= 2;  
    }
    ll dp1[2] = {0, 0};
    ll dp2[2][2] = {{0, 0}, {0, 0}};

    ll ans = 0;  

    for (int i = 0; i < n; i++) {
        int b = a[i];
        ll new_longer = 0;
        for (int x = 0; x < 2; x++) {
            for (int y = 0; y < 2; y++) {
                if ((x + y + b) % 2 == 0) {
                    new_longer = (new_longer + dp2[x][y]) % mod;
                }
            }
        }
        ans = (ans + new_longer) % mod;
        ll ndp2[2][2] = {{0,0},{0,0}};
        for (int x = 0; x < 2; x++) {
            ndp2[x][b] = (ndp2[x][b] + dp1[x]) % mod;
        }
        for (int x = 0; x < 2; x++) {
            for (int y = 0; y < 2; y++) {
                if ((x + y + b) % 2 == 0) {
                    ndp2[y][b] = (ndp2[y][b] + dp2[x][y]) % mod;
                }
            }
        }
        dp1[b] = (dp1[b] + 1) % mod;  
        memcpy(dp2, ndp2, sizeof dp2);
    }

    cout << ans << "\n";
}

int main() {
    Code By pdubey1924_macro

    ll t = 1;
    solve();
    return 0;
}
