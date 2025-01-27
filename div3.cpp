#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    sort(arr.begin(), arr.end());  
    int score = 0;
    
    for (int i = 0, j = arr.size() - 1; i < j;) {
        if (arr[i] + arr[j] == k) {
            score++;
            arr.erase(arr.begin() + j);  
            arr.erase(arr.begin() + i);  
            j -= 2;  
        } else if (arr[i] + arr[j] < k) {
            i++;  
        } else {
            j--;  
        }
    }
    
    cout << score << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
