#include <bits/stdc++.h>
using namespace std;

// ek aur logic all are mapped according i == 1,i ==2 accordingly so just update the difference where it is not mergerd
// like if i == 1 and mapped == 3
// answer = 3-1 = 2;

long gcd(long a, long b) {
    if (b == 0) {
        return a;  // If b is 0, the GCD is a
    } else {
        return gcd(b, a % b);  // Recursively call gcd(b, a % b) until b is 0
    }
}

void solve() {
    int t;
    cin >> t;  
    while (t--) {  
        long n;
        cin >> n; 
        
        long g(0);  // Initialize GCD to 0
        
        for (long p = 1; p <= n; p++) {  
            long x;
            cin >> x;  
            
            long diff = p - x;  // Calculate the difference between the index p and the value x
            
            diff = (diff > 0) ? diff : -diff;  // Take the absolute value of the difference
            
            g = gcd(g, diff);  // Update the GCD with the current difference
        }
        
        cout << g << endl;  
    }
}

int main() {
    ios::sync_with_stdio(false);  
    cin.tie(0);  
    solve();  
    return 0;
}
