#include <bits/stdc++.h>
using namespace std;

// Efficient binary exponentiation function
long long int binpow(long long int base, long long int exponent) {
    long long int result = 1;
    while (exponent > 0) {
        if (exponent & 1) {
            result *= base;
        }
        base *= base;
        exponent >>= 1;
    }
    return result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--){
        long long int n, q; 
        cin >> n >> q;
    
        vector<long long int> a(n);
        for (long long int i = 0; i < n; ++i) {
            cin >> a[i];
        }
    
        map<long long int, bool> m;
        vector<long long int> b;
    
        for (long long int i = 0; i < q; ++i) {
            long long int ai; 
            cin >> ai;
            if (m[ai] == false) {
                b.push_back(ai);
            }
            m[ai] = true;
        }
    
        for (auto i : b) {
            long long int v = binpow(2, i);
            for (long long int j = 0; j < n; ++j) {
                if (a[j] % v == 0) {
                    a[j] += binpow(2, i - 1);
                }
            }
        }
    
        for (long long int i = 0; i < n; ++i) {
            cout << a[i] << ' ';
        }
        cout << '\n';
    
    }
    return 0;
}
