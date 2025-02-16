#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    unordered_set<int> distinct_elements(a.begin(), a.end());
    int initial_score = n - distinct_elements.size();

    unordered_map<int, int> first_occurrence, last_occurrence;
    for (int i = 0; i < n; ++i) {
        if (first_occurrence.find(a[i]) == first_occurrence.end()) {
            first_occurrence[a[i]] = i;
        }
        last_occurrence[a[i]] = i;
    }

    vector<int> single_occurrence_elements;
    for (const auto& pair : first_occurrence) {
        if (pair.second == last_occurrence[pair.first]) {
            single_occurrence_elements.push_back(pair.first);
        }
    }

    if (single_occurrence_elements.empty()) {
        cout << "0\n";
        return;
    }

    int min_l = n, min_r = -1;
    for (int element : single_occurrence_elements) {
        int pos = first_occurrence[element];
        min_l = min(min_l, pos);
        min_r = max(min_r, pos);
    }

    int new_length = n - (min_r - min_l + 1);
    unordered_set<int> new_distinct;
    for (int i = 0; i < min_l; ++i) {
        new_distinct.insert(a[i]);
    }
    for (int i = min_r + 1; i < n; ++i) {
        new_distinct.insert(a[i]);
    }
    int new_score = new_length - new_distinct.size();

    if (new_score > initial_score) {
        cout << min_l + 1 << " " << min_r + 1 << "\n";
    } else if (new_score == initial_score) {
        if (new_length < n) {
            cout << min_l + 1 << " " << min_r + 1 << "\n";
        } else {
            cout << "0\n";
        }
    } else {
        cout << "0\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
