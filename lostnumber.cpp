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
ll moduloMultiplication(ll a, ll b, ll mod) {
    ll res = 0;
    a %= mod;
    while (b) {
        if (b & 1)
            res = (res + a) % mod;
        b >>= 1;
    }
    return res;
}
ll powermod(ll x, ll y, ll p) {
    ll res = 1;
    x = x % p;
    if (x == 0)
        return 0;
    while (y > 0) {
        if (y & 1)
            res = (res * x) % p;
        y = y >> 1;
        x = (x * x) % p;
    }
    return res;
}

// Sorting
bool sorta(const pair<int, int> &a, const pair<int, int> &b) { return (a.second < b.second); }
bool sortd(const pair<int, int> &a, const pair<int, int> &b) { return (a.second > b.second); }

// Bits
string decToBinary(int n) {
    string s = "";
    int i = 0;
    while (n > 0) {
        s = to_string(n % 2) + s;
        n = n / 2;
        i++;
    }
    return s;
}
ll binaryToDecimal(string n) {
    string num = n;
    ll dec_value = 0;
    int base = 1;
    int len = num.length();
    for (int i = len - 1; i >= 0; i--) {
        if (num[i] == '1')
            dec_value += base;
        base = base * 2;
    }
    return dec_value;
}

// Check
bool isPrime(ll n) {
    if (n <= 1)
        return false;
    if (n <= 3)
        return true;
    if (n % 2 == 0 || n % 3 == 0)
        return false;
    for (int i = 5; i * i <= n; i = i + 6) {
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
    }
    return true;
}
bool isPowerOfTwo(int n) {
    if (n == 0)
        return false;
    return (ceil(log2(n)) == floor(log2(n)));
}
bool isPerfectSquare(ll x) {
    if (x >= 0) {
        ll sr = sqrt(x);
        return (sr * sr == x);
    }
    return false;
}

// Code by Prashant Dubey
// Language C++
// Code


void solve() {
    
    set<int> special = {4, 8, 15, 16, 23, 42};
    
    ll prod12, prod13, prod14, prod15;
    
    cout << "? 1 2" << endl;
    fflush(stdout);
    cin >> prod12;
    
    cout << "? 1 3" << endl;
    fflush(stdout);
    cin >> prod13;
    
    cout << "? 1 4" << endl;
    fflush(stdout);
    cin >> prod14;
    
    cout << "? 1 5" << endl;
    fflush(stdout);
    cin >> prod15;
    
    int a1, a2, a3, a4, a5, a6;
    bool found = false;
   
    for (int cand : special) {
     
        if (prod12 % cand != 0 || prod13 % cand != 0 || prod14 % cand != 0 || prod15 % cand != 0)
            continue;
            
        int cand_a2 = prod12 / cand;
        int cand_a3 = prod13 / cand;
        int cand_a4 = prod14 / cand;
        int cand_a5 = prod15 / cand;
        
        if (special.count(cand_a2) == 0 || special.count(cand_a3) == 0 ||
            special.count(cand_a4) == 0 || special.count(cand_a5) == 0)
            continue;
        
      
        set<int> used = {cand, cand_a2, cand_a3, cand_a4, cand_a5};
        if (used.size() != 5)
            continue;
        
       
        a1 = cand;
        a2 = cand_a2;
        a3 = cand_a3;
        a4 = cand_a4;
        a5 = cand_a5;

        a6 = 108 - (a1 + a2 + a3 + a4 + a5);
        found = true;
        break;
    }
    cout << "! " << a1 << " " << a2 << " " << a3 << " " << a4 << " " << a5 << " " << a6 << endl;
    fflush(stdout);
}

// Main
int main() {
    Code By pdubey1924_macro  
    solve();
    return 0;
}
