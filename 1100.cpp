#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

void solve() {
    int t;
    cin >> t;  // number of test cases
    
    while (t--) {
        long long n, k;
        cin >> n >> k;  // n = length of the array, k = number of operations
        vector<long long> a(n);
        
        for (long long i = 0; i < n; ++i) {
            cin >> a[i];
        }

        // Step 1: Sort the array
        sort(a.begin(), a.end());

        // Step 2: Compute all pairwise absolute differences
        vector<long long> diffs;
        for (long long i = 0; i < n; ++i) {
            for (long long j = i + 1; j < n; ++j) {
                diffs.push_back(abs(a[j] - a[i]));
            }
        }

        // Step 3: Sort the differences
        sort(diffs.begin(), diffs.end());

        // Step 4: Perform the operations
        for (long long i = 0; i < k; ++i) {
            if (!diffs.empty()) {
                long long min_diff = diffs[0];
                // Reduce the minimum element of the array by the smallest diff
                a[0] -= min_diff;
                // After an operation, it is optimal to re-sort the array to continue minimizing.
                sort(a.begin(), a.end());
                diffs.erase(diffs.begin());  // Remove the used diff
            } else {
                break;  // If no more diffs left, break early
            }
        }

        // Step 5: Output the minimum value of the array after k operations
        cout << a[0] << endl;
    }
}

int main() {
    solve();  // Call the solve function
    return 0;
}
