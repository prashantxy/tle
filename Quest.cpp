#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
 
// Global variables used in the check function.
 
// S: the sorted version of the entire array (of length m = n)
// prefix: the prefix sums of S
// For a given query value v, we will remove one occurrence (we choose the first occurrence)
// Let pos = lower_bound(S.begin(), S.end(), v) - S.begin();
// Then the "modified" array A (the available elements for absorption) is:
///   For indices i in [0, pos-1]: A[i] = S[i]
///   For indices i in [pos, m-2]: A[i] = S[i+1]
// We can compute the prefix sum for A on the fly using prefix of S.
 
// Given a candidate t (0 <= t <= L where L = m-1) meaning we try to absorb t elements from A,
// this function returns whether starting with score = v we can absorb t elements.
 
bool canAbsorb(ll v, int t, int pos, const vector<ll>& S, const vector<ll>& prefix) {
    // t==0 always works (absorbing 0 additional elements)
    if(t == 0) return true;
    ll P; // sum of first t elements in A
    ll last; // the t-th element in A (0-indexed: A[t-1])
    if(t <= pos) {
        // All t elements come from S[0..t-1]
        P = prefix[t-1];
        last = S[t-1];
    } else {
        // For indices before pos, they are S[0..pos-1], and then the rest come from S[pos+1...]
        ll sumBefore = (pos > 0 ? prefix[pos-1] : 0);
        // Number of elements taken after pos: t - pos.
        // Their sum is prefix[t] - prefix[pos]  (because prefix[t] is sum of S[0..t], and we subtract the sum of S[0..pos])
        ll sumAfter = prefix[t] - prefix[pos];
        P = sumBefore + sumAfter;
        // The t-th element in A is: if t-1 < pos, it would be S[t-1], else it is S[(t-1) + 1] = S[t].
        last = S[t];  // (since t > pos, t-1 >= pos)
    }
    // To be able to absorb t elements, we must have v >= A[0] and then eventually v + P >= (the last element we try to absorb)
    // Note: A[0] is S[0] if pos > 0, but if pos == 0 then A[0] = S[1].
    ll A0 = (pos > 0 ? S[0] : (S.size() >= 2 ? S[1] : LLONG_MAX)); // if pos==0 and m==1, there’s nothing to absorb.
    return (v >= A0 && v + P >= last);
}
 
// For a given starting value v, with sorted array S and its prefix sums (of length m),
// and pos = first occurrence of v in S, return the maximum number t (0 <= t <= m-1) that can be absorbed.
 
int maxAbsorbable(ll v, int pos, const vector<ll>& S, const vector<ll>& prefix) {
    int m = S.size();
    int L = m - 1;  // after removal, there are L elements available.
    int lo = 0, hi = L;
    int best = 0;
    while(lo <= hi) {
        int mid = (lo + hi) / 2;
        if(canAbsorb(v, mid, pos, S, prefix)) {
            best = mid;
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }
    return best;
}
 
// solve() processes one test case.
void solve(){
    int n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    // Build sorted copy and its prefix sums.
    vector<ll> S = a;
    sort(S.begin(), S.end());
    int m = S.size();
    vector<ll> prefix(m);
    prefix[0] = S[0];
    for (int i = 1; i < m; i++){
        prefix[i] = prefix[i-1] + S[i];
    }
    
    // We'll precompute the answer for each distinct value v.
    unordered_map<ll, int> dp;
    dp.reserve(m * 2);
    
    // Process S to handle each distinct v.
    for (int i = 0; i < m; ) {
        ll v = S[i];
        // For v, find the first occurrence index.
        int pos = i;  // because S is sorted, i is the first occurrence of v.
        // Compute the maximum additional removals when starting with score = v.
        int cnt = maxAbsorbable(v, pos, S, prefix);
        dp[v] = cnt;
        // Skip all copies of v.
        int j = i + 1;
        while(j < m && S[j] == v) j++;
        i = j;
    }
    
    // For each element in the original array, output dp[a[i]].
    // (That is, if you remove that element and set your score to a[i], you can remove dp[a[i]] additional elements.)
    for (int i = 0; i < n; i++){
        cout << dp[a[i]] << " ";
    }
    cout << "\n";
}
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
