#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        
        long long minChange = 0; 
        int bestL = 1, bestR = 1;
        
        for (int l = 0; l < n; l++) {
            long long currentSum = 0;
            long long minSum = 0;
            int currentR = l;
            for (int r = l + 1; r < n; r++) {
                if (a[r] > a[l]) currentSum += 1;
                else if (a[r] < a[l]) currentSum -= 1;
                if (currentSum < minSum) {
                    minSum = currentSum;
                    currentR = r;
                }
            }
        
            if (minSum < minChange) {
                minChange = minSum;
                bestL = l + 1; 
                bestR = currentR + 1;
            }
        }
        
        cout << bestL << " " << bestR << "\n";
    }
    return 0;
}