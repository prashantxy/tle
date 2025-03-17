#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for (int i = 0; i < (n); ++i)
#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define ALL(x) (x).begin(), (x).end()
#define pb push_back
#define fi first
#define se second
typedef long long ll;

const ll INF = 1LL << 60;  // a very large number
const int L = 11, MAXSUM = 70;  // Using coins 1..L, so max total exponent is <= 66

// dp[i][p][q] = minimal cost to achieve total exponent p for x and q for y using coins 1..i.
ll dp[L+1][MAXSUM+1][MAXSUM+1];

struct PairCost {
    int p, q;
    ll cost;
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Initialize DP table.
    REP(p, MAXSUM+1) REP(q, MAXSUM+1) dp[0][p][q] = INF;
    dp[0][0][0] = 0;
    FOR(i, 1, L+1) {
        REP(p, MAXSUM+1) REP(q, MAXSUM+1) {
            // Option 1: do not use coin i.
            dp[i][p][q] = dp[i-1][p][q];
            // Option 2: use coin i for x (if possible).
            if(p >= i && dp[i-1][p-i][q] != INF) {
                dp[i][p][q] = min(dp[i][p][q], dp[i-1][p-i][q] + (1LL << i));
            }
            // Option 3: use coin i for y (if possible).
            if(q >= i && dp[i-1][p][q-i] != INF) {
                dp[i][p][q] = min(dp[i][p][q], dp[i-1][p][q-i] + (1LL << i));
            }
        }
    }

    // Collect all (p, q, cost) pairs that are achievable.
    vector<PairCost> vec;
    REP(p, MAXSUM+1) {
        REP(q, MAXSUM+1) {
            if(dp[L][p][q] < INF) {
                vec.pb({p, q, dp[L][p][q]});
            }
        }
    }
    // Sort by cost (lowest cost first).
    sort(ALL(vec), [](const PairCost &a, const PairCost &b) {
        return a.cost < b.cost;
    });
    
    int t;
    cin >> t;
    while(t--){
        ll x, y;
        cin >> x >> y;
        if(x == y){
            cout << 0 << "\n";
            continue;
        }
        ll best = INF;
        // Try every (p,q) pair from our precomputed vector.
        for(auto &pc : vec){
            if(pc.cost >= best) break;  // early break, since vec is sorted by cost.
            // newX = floor(x/2^p), newY = floor(y/2^q)
            ll newX = x >> pc.p;
            ll newY = y >> pc.q;
            if(newX == newY){
                best = min(best, pc.cost);
            }
        }
        cout << best << "\n";
    }
    return 0;
}
