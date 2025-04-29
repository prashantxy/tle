#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

const ll mod = 1e9 + 7;

ll binpow(ll base, ll exp, ll mod) {
    ll res = 1;
    while (exp) {
        if (exp % 2) res = (res * base) % mod;
        base = (base * base) % mod;
        exp /= 2;
    }
    return res;
}

void solve() {
    ll n;
    cin >> n;
    
    vector<pll> fact(n);
    for (ll i = 0; i < n; i++) {
        cin >> fact[i].first >> fact[i].second;
    }
    
    ll num_divisors = 1;  // Number of divisors
    ll sum_divisors = 1;  // Sum of divisors
    ll product_divisors = 1;  // Product of divisors
    
    // Calculate the number of divisors (product of (exponent + 1) for each prime factor)
    for (auto &it : fact) {
        num_divisors = (num_divisors * (it.second + 1)) % mod;
    }
    
    // Calculate the sum of divisors using the geometric series formula
    for (auto &it : fact) {
        ll numerator = (binpow(it.first, it.second + 1, mod) - 1 + mod) % mod;  // p^(e+1) - 1
        ll denominator = (it.first - 1 + mod) % mod;  // p - 1
        ll inv_denominator = binpow(denominator, mod - 2, mod);  // Inverse of (p - 1)
        ll geo_sum = (numerator * inv_denominator) % mod;  // Geometric sum formula
        sum_divisors = (sum_divisors * geo_sum) % mod;
    }
    
    // Calculate the product of divisors using the formula n^(num_divisors / 2)
    product_divisors = binpow(product_divisors, num_divisors / 2, mod);
    
    cout << num_divisors << " " << sum_divisors << " " << product_divisors << "\n";
}

int main() {
    solve();
    return 0;
}
