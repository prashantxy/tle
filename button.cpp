#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<pair<int, int>> a(n); 
    for (int i = 0; i < n; ++i) {
        cin >> a[i].first;
        a[i].second = i + 1; 
    }

    sort(a.begin(), a.end()); 

    vector<int> result;
    int total_days = 0;

    for (int i = 0; i < n; ++i) {
        if (total_days + a[i].first <= k) {
            total_days += a[i].first;
            result.push_back(a[i].second);
        } else {
            break;
        }
    }

    cout << result.size() << '\n';
    for (int idx : result)
        cout << idx << ' ';
    cout << '\n';

    return 0;
}
