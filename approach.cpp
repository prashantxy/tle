#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    set<int> st;
    
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        st.insert(a[i]);
    }
    
    int initial_score = n - st.size();  // Initial score before any removal

    if (n == 1) {
        cout << "1 1\n"; // The only option is removing the single element
        return;
    }

    map<int, vector<int>> pos; // Store positions of each element
    for (int i = 0; i < n; i++) {
        pos[a[i]].push_back(i);
    }

    int max_score = initial_score;
    int best_l = -1, best_r = -1;

    for (auto &[val, indices] : pos) {
        int l = indices.front(), r = indices.back(); // First and last occurrence
        int new_length = n - (r - l + 1);
        set<int> new_distinct;
        
        for (int i = 0; i < l; i++) new_distinct.insert(a[i]);  // Left part
        for (int i = r + 1; i < n; i++) new_distinct.insert(a[i]); // Right part

        int new_score = new_length - new_distinct.size();

        if (new_score > max_score || (new_score == max_score && new_length < n - (best_r - best_l + 1))) {
            max_score = new_score;
            best_l = l + 1;
            best_r = r + 1;
        }
    }

    if (best_l == -1) {
        cout << "0\n"; // No removal is the best choice
    } else {
        cout << best_l << " " << best_r << "\n";
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
