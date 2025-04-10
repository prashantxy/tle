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
#define debug(x) cerr << #x << " "; cerr << x << " "; cerr << endl;
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
    if (b == 0) return a;
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
        a = (a + a) % mod;
    }
    return res;
}
ll powermod(ll x, ll y, ll p) {
    ll res = 1;
    x %= p;
    if (x == 0) return 0;
    while (y > 0) {
        if (y & 1)
            res = (res * x) % p;
        y >>= 1;
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
    while (n > 0) {
        s = to_string(n % 2) + s;
        n /= 2;
    }
    return s;
}
ll binaryToDecimal(string n) {
    ll dec_value = 0;
    int base = 1;
    int len = n.length();
    for (int i = len - 1; i >= 0; i--) {
        if (n[i] == '1')
            dec_value += base;
        base *= 2;
    }
    return dec_value;
}

// Checks
bool isPrime(ll n) {
    if (n <= 1) return false;
    if (n <= 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    for (int i = 5; i * i <= n; i += 6)
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
    return true;
}
bool isPowerOfTwo(int n) {
    if (n == 0) return false;
    return (ceil(log2(n)) == floor(log2(n)));
}
bool isPerfectSquare(ll x) {
    if (x >= 0) {
        ll sr = sqrt(x);
        return (sr * sr == x);
    }
    return false;
}

// Graph Section
void dfs(int node, vector<bool> &visited, const vector<vector<int>> &graph) {
    visited[node] = true;
    for (int neighbor : graph[node])
        if (!visited[neighbor])
            dfs(neighbor, visited, graph);
}

void bfs(int start, vector<bool> &visited, const vector<vector<int>> &graph) {
    queue<int> q;
    q.push(start);
    visited[start] = true;
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        for (int neighbor : graph[node])
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
    }
}

struct DSU {
    vector<int> parent, rank;
    DSU(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        fl(i, n) parent[i] = i;
    }
    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }
    void unionSet(int x, int y) {
        int px = find(x), py = find(y);
        if (px == py) return;
        if (rank[px] < rank[py]) swap(px, py);
        parent[py] = px;
        if (rank[px] == rank[py]) rank[px]++;
    }
};


vll primes;
void sieve(ll MAX_N) {
    vector<bool> isPrime(MAX_N + 1, true);
    isPrime[0] = isPrime[1] = false;
    for (ll i = 2; i * i <= MAX_N; i++)
        if (isPrime[i])
            for (ll j = i * i; j <= MAX_N; j += i)
                isPrime[j] = false;

    for (ll i = 2; i <= MAX_N; i++)
        if (isPrime[i])
            primes.pb(i);
}

ll global_mex(const vll &a) {
    ll n = a.size();
    vector<bool> present(n + 2, false);
    for (auto &x : a)
        if (x <= n)
            present[x] = true;

    ll m = 0;
    while (present[m]) m++;
    return m;
}

bool canPartition(const vll &a, ll k, ll x) {
    if (x == 0) return true;
    ll countSegments = 0;
    vector<bool> seen(x, false);
    ll cnt = 0;

    for (auto num : a) {
        if (num < x && !seen[num]) {
            seen[num] = true;
            cnt++;
        }
        if (cnt == x) {
            countSegments++;
            fill(seen.begin(), seen.end(), false);
            cnt = 0;
            if (countSegments >= k) return true;
        }
    }
    return false;
}

void solve() {
   
}

int main() {
    Code By pdubey1924_macro
    const ll MAX_N = 10000000;
    sieve(MAX_N);

    ll t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
