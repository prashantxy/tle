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

// Constants
const lld pi = 3.141592653589793238;
const ll INF = LONG_LONG_MAX;
const ll mod = 1e9 + 7;

// Macros
#define fl(i, n) for (int i = 0; i < n; i++)
#define vr(v) v.begin(), v.end()

// BIT (Fenwick Tree) implementation.
struct Fenw {
    int n;
    vector<int> fenw;
    Fenw(int n): n(n), fenw(n + 1, 0) { }
    void update(int i, int delta) {
        for(; i <= n; i += i & -i)
            fenw[i] += delta;
    }
    
   
    int query(int i) {
        int sum = 0;
        for(; i; i -= i & -i)
            sum += fenw[i];
        return sum;
    }
};

void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    fl(i, n) {
        cin >> a[i];
    }
    int size = n + q;
    Fenw bit(size);
    vector<set<int>> colorPos(51);
    for (int i = 0; i < n; i++){
        int pos = q + 1 + i; 
        bit.update(pos, 1);
        colorPos[a[i]].insert(pos);
    }
    int current_top = q; 
    while(q--){
        int t;
        cin >> t;
        int pos = *colorPos[t].begin();
        int rank = bit.query(pos);
        cout << rank << " ";
        bit.update(pos, -1);
        colorPos[t].erase(pos);
        bit.update(current_top, 1);
        colorPos[t].insert(current_top);
        current_top--;
    }
    
    cout << "\n";
}
 
// Main
int main() {
    Code By pdubey1924_macro  
    solve();
    return 0;
}
