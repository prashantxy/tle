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

// Mathematical functions
ll gcd(ll a, ll b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

// Code by Prashant Dubey

// Sieve function (unused in solve but kept from the template)
vector<ll> primes;
void sieve(ll MAX_N) {
    vector<bool> isPrime(MAX_N + 1, true);
    isPrime[0] = isPrime[1] = false;
    for (ll i = 2; i * i <= MAX_N; i++) {
        if (isPrime[i]) {
            for (ll j = i * i; j <= MAX_N; j += i) {
                isPrime[j] = false;
            }
        }
    }
    for (ll i = 2; i <= MAX_N; i++) {
        if (isPrime[i])
            primes.push_back(i);
    }
}

void solve() {
    ll n, m;
    cin >> n >> m;
  
    vector<ll> arr(n), arr1(m);
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }
    for (int i = 0; i < m; i++){
        cin >> arr1[i];
    }
    
    ll d = 0;
    for (int i = 1; i < n; i++){
        d = gcd(d, abs(arr[i] - arr[0]));
    }
    
    for (int i = 0; i < m; i++){
        ll answer = gcd(arr[0] + arr1[i], d);
        cout << answer << " ";
    }
    cout << "\n";
}

int main() {
    Code By pdubey1924_macro  
    const ll MAX_N = 10000000;
    sieve(MAX_N);  
    
    solve();
    
    return 0;
}
