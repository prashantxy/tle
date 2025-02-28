#include <bits/stdc++.h>
using namespace std;

void solve() {
    int N;
    long long X;
    cin >> N >> X;
    vector<long long> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    map<long long, int> original_freq;
    for (long long num : A) {
        original_freq[num]++;
    }

    int original_max = 0;
    for (auto& p : original_freq) {
        original_max = max(original_max, p.second);
    }

    if (X == 1) {
        cout << original_max << "\n";
        return;
    }

    unordered_map<long long, int> current_sums;
    unordered_map<long long, int> global_maxs;

    for (int i = 0; i < N; ++i) {
        long long current_value = A[i];
        long long K1 = current_value * X;

        int new_sum_k1 = max(0, current_sums[K1] + 1);
        current_sums[K1] = new_sum_k1;
        if (global_maxs.find(K1) == global_maxs.end() || new_sum_k1 > global_maxs[K1]) {
            global_maxs[K1] = new_sum_k1;
        }

        if (current_value % X == 0) {
            long long K2 = current_value;
            int new_sum_k2 = max(0, current_sums[K2] - 1);
            current_sums[K2] = new_sum_k2;
            if (global_maxs.find(K2) == global_maxs.end() || new_sum_k2 > global_maxs[K2]) {
                global_maxs[K2] = new_sum_k2;
            }
        }
    }

    int max_candidate = original_max;
    for (auto& entry : global_maxs) {
        long long K = entry.first;
        int gain = entry.second;
        int original = original_freq.count(K) ? original_freq[K] : 0;
        max_candidate = max(max_candidate, original + gain);
    }

    cout << max(max_candidate, original_max) << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}        