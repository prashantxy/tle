#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// Debugging
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
const ll M = 998244353;

// TypeDefs
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
#define rv(v) v.rbegin(), v.rend()

// Debug
#ifdef Prashant
#define debug(x) cerr << #x << " = " << x << endl;
#else
#define debug(x)
#endif

// Operator Overloads
template <typename T1, typename T2>
istream &operator>>(istream &istream, pair<T1, T2> &p) {
    return (istream >> p.first >> p.second);
}
template <typename T>
istream &operator>>(istream &istream, vector<T> &v) {
    for (auto &it : v) cin >> it;
    return istream;
}
template <typename T1, typename T2>
ostream &operator<<(ostream &ostream, const pair<T1, T2> &p) {
    return (ostream << p.first << " " << p.second);
}
template <typename T>
ostream &operator<<(ostream &ostream, const vector<T> &c) {
    for (auto &it : c) cout << it << " ";
    return ostream;
}

// Utility Functions
template <typename T>
void print(T &&t) { cout << t << "\n"; }

void printarr(ll arr[], ll n) {
    fl(i, n) cout << arr[i] << " ";
    cout << "\n";
}

template <typename T>
void printvec(vector<T> v) {
    for (auto &x : v) cout << x << " ";
    cout << "\n";
}

template <typename T>
ll sumvec(vector<T> v) {
    return accumulate(v.begin(), v.end(), 0LL);
}

// Math
ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }
ll lcm(ll a, ll b) { return (a / gcd(a, b)) * b; }

ll powermod(ll x, ll y, ll p) {
    ll res = 1;
    x %= p;
    if (x == 0) return 0;
    while (y) {
        if (y & 1) res = res * x % p;
        x = x * x % p;
        y >>= 1;
    }
    return res;
}

ll mod_div(ll p, ll q) {
    return p * powermod(q, M - 2, M) % M;
}

// Factorial Precomputation
vector<ll> fact, ifact;
void factCompute(int N = 1e6) {
    fact.assign(N + 1, 1);
    ifact.assign(N + 1, 1);
    for (int i = 1; i <= N; i++) fact[i] = fact[i - 1] * i % M;
    ifact[N] = powermod(fact[N], M - 2, M);
    for (int i = N - 1; i >= 0; i--)
        ifact[i] = ifact[i + 1] * (i + 1) % M;
}

// Primes
vll primes;
void sieve(ll MAX_N) {
    vector<bool> isPrime(MAX_N + 1, true);
    isPrime[0] = isPrime[1] = false;
    for (ll i = 2; i * i <= MAX_N; i++)
        if (isPrime[i])
            for (ll j = i * i; j <= MAX_N; j += i)
                isPrime[j] = false;
    for (ll i = 2; i <= MAX_N; i++)
        if (isPrime[i]) primes.pb(i);
}

// Bit Manipulations
string decToBinary(int n) {
    string s = "";
    while (n) {
        s = to_string(n % 2) + s;
        n /= 2;
    }
    return s;
}
ll binaryToDecimal(string n) {
    return stoll(n, nullptr, 2);
}

// Checks
bool isPrime(ll n) {
    if (n <= 1) return false;
    if (n <= 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    for (int i = 5; i * i <= n; i += 6)
        if (n % i == 0 || n % (i + 2) == 0) return false;
    return true;
}
bool isPowerOfTwo(int n) { return n && !(n & (n - 1)); }
bool isPerfectSquare(ll x) {
    ll sr = sqrt(x);
    return sr * sr == x;
}

// Graph Algorithms
void dfs(int node, vector<bool> &visited, const vector<vector<int>> &graph) {
    visited[node] = true;
    for (int neighbor : graph[node])
        if (!visited[neighbor]) dfs(neighbor, visited, graph);
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
        parent.resize(n); rank.resize(n, 0);
        fl(i, n) parent[i] = i;
    }
    int find(int x) {
        if (parent[x] != x) parent[x] = find(parent[x]);
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

void solve() {
    vector<ll> c(27, 0);
    for (int i = 1; i <= 26; i++) cin >> c[i];

    int n = accumulate(c.begin(), c.end(), 0LL);

    vector<vector<ll>> dp(27, vector<ll>(n + 1, 0));
    dp[0][0] = 1;

    for (int i = 1; i <= 26; i++) {
        for (int j = 0; j <= n / 2; j++) {
            dp[i][j] = dp[i - 1][j];
            if (c[i] > 0 && j - c[i] >= 0)
                dp[i][j] = (dp[i][j] + dp[i - 1][j - c[i]]) % M;
        }
    }

    ll ans = dp[26][n / 2] * fact[n / 2] % M * fact[(n + 1) / 2] % M;

    for (int i = 1; i <= 26; i++) {
        ans = mod_div(ans, fact[c[i]]);
    }

    cout << ans << "\n";
}

int main() {
    Code By pdubey1924_macro

    const ll MAX_N = 1000000;
    sieve(MAX_N);
    factCompute();

    ll t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
