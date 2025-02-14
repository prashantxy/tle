#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int tc;
    cin >> tc;
    while (tc--) {
        int w, h;
        cin >> w >> h;
        
        vector<vector<int>> v(4); // Stores four sets of points

        for (int i = 0; i < 4; i++) {
            int k;
            cin >> k;
            v[i].resize(k);
            for (int j = 0; j < k; j++) {
                cin >> v[i][j];
            }
        }

        ll max_area = 0;

        for (int i = 0; i < 4; i++) {
            int segment_length = v[i].back() - v[i].front(); // Max segment length
            ll area = (i < 2) ? (1LL * segment_length * h) : (1LL * segment_length * w);
            max_area = max(max_area, area);
        }

        cout << max_area << '\n';
    }
    return 0;
}
