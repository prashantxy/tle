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
const ll INF = 1e15; // large enough for our sums (n<=3000, positions up to 3000)
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

// Global DP arrays and pointer arrays.
const ll INF_LL = 1e15;
 
void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    fl(i, n) cin >> a[i];
    
    // For colors 1..k, store positions (1-indexed).
    vector<vector<int>> pos(k+1);
    fl(i, n) {
        int c = a[i];
        pos[c].pb(i+1);  // store 1-indexed positions
    }
    
    // Check that every color appears at least once (guaranteed by problem).
    
    // We'll do DP on colors in fixed order: 1,2,...,k.
    // Let dp[c][j] be the minimal sum of chosen positions for colors 1..c,
    // if for color c we choose its j-th occurrence (0-indexed in pos[c]).
    // We also store a pointer to reconstruct.
    const int MAX_COLOR = k;
    vector<vector<ll>> dp(MAX_COLOR+1);
    vector<vector<int>> par(MAX_COLOR+1);
    for (int c = 1; c <= MAX_COLOR; c++) {
        dp[c].resize(pos[c].size(), INF_LL);
        par[c].resize(pos[c].size(), -1);
    }
    
    // Base: for color 1, dp[1][j] = pos[1][j] (the cost is just the chosen position).
    for (int j = 0; j < (int)pos[1].size(); j++) {
        dp[1][j] = pos[1][j];
    }
    
    // Transition: for colors 2 to k.
    for (int c = 2; c <= MAX_COLOR; c++) {
        for (int j = 0; j < (int)pos[c].size(); j++) {
            int curPos = pos[c][j];
            // We want to choose an occurrence for color c-1 that is less than curPos.
            ll best = INF_LL;
            int best_i = -1;
            for (int i = 0; i < (int)pos[c-1].size(); i++) {
                if(pos[c-1][i] < curPos) {
                    if(dp[c-1][i] < best) {
                        best = dp[c-1][i];
                        best_i = i;
                    }
                }
            }
            if(best < INF_LL) {
                dp[c][j] = best + curPos;
                par[c][j] = best_i;
            }
        }
    }
    
    // Now, for each valid ending for color k, reconstruct the chosen sequence (which will be increasing).
    ll ans = INF_LL;
    vector<int> bestSeq;
    for (int j = 0; j < (int)pos[k].size(); j++) {
        if(dp[k][j] < INF_LL) {
            // Reconstruct chosen positions for colors 1..k.
            vector<int> seq(k+1, 0);
            int cur = j;
            for (int c = k; c >= 1; c--) {
                seq[c] = pos[c][cur];
                cur = (c==1? -1 : par[c][cur]);
            }
            // Compute cost to group these chosen positions.
            // Let p[1..k] = seq[1..k]. (They are in increasing order.)
            // Let m = floor((k+1)/2). Then cost = sum_{i=1}^{k} |p_i - (p_m - m + i)|.
            int m = (k+1)/2;
            int median = seq[m];
            ll curCost = 0;
            for (int i = 1; i <= k; i++) {
                int target = median - m + i;
                curCost += abs(seq[i] - target);
            }
            if(curCost < ans) {
                ans = curCost;
                bestSeq = seq;
            }
        }
    }
    
    // Output the answer.
    cout << ans << "\n";
}
 
int main(){
    Code By pdubey1924_macro  
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}
 
// End
