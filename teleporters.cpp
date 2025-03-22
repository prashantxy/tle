#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while (t--) {
        int n, c;
        cin >> n >> c;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        vector<pair<long long, int>> tele_costs;
        for (int i = 0; i < n; i++) {
            tele_costs.push_back({(long long)(i + 1) + a[i], i + 1});
        }
        
        sort(tele_costs.begin(), tele_costs.end());
        
        int used = 0;
        long long total_spent = 0;
        for (auto &p : tele_costs) {
            if (total_spent + p.first <= c) {
                total_spent += p.first;
                used++;
            } else {
                break;
            }
        }
        
        cout << used << "\n";
    }
    
    return 0;
}
