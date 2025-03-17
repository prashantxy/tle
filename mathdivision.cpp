#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll MOD = 1e9 + 7;


ll modpow(ll a, ll b, ll mod) {
    ll res = 1;
    a %= mod;
    while (b > 0) {
        if (b & 1)
            res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    vector<int> ns(t);
    vector<string> binaries(t);
    for (int i = 0; i < t; ++i) {
        cin >> ns[i];
        cin >> binaries[i];
    }

    int maxN = *max_element(ns.begin(), ns.end());

    // Precompute powers of 2 up to maxN + 1
    vector<ll> pow2(maxN + 2, 1);
    for (int i = 1; i <= maxN + 1; ++i)
        pow2[i] = (pow2[i - 1] * 2) % MOD;

  
    vector<ll> invPow2(maxN + 2, 1);
    for (int i = 0; i <= maxN + 1; ++i)
        invPow2[i] = modpow(pow2[i], MOD - 2, MOD);

    
    vector<ll> numer(maxN + 2, 0);
    vector<ll> denom(maxN + 2, 1);

    numer[1] = 0; // 0/1
    denom[1] = 1;

    for (int n = 2; n <= maxN + 1; ++n) {
        numer[n] = (pow2[n - 1] - 1 + MOD) % MOD; // p = 2^(n - 1) - 1
        denom[n] = pow2[n - 1];                   // q = 2^(n - 1)
    }

    for (int i = 0; i < t; ++i) {
        int n = ns[i];

        ll p = numer[n];
        ll q = denom[n];

        ll result = p * modpow(q, MOD - 2, MOD) % MOD;
        cout << result << '\n';
    }

    return 0;
}
