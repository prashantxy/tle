#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        long long sum = 0;
        for (int i = 0; i < n; i++) {
            int a;
            cin >> a;
            sum += a;
        }
        cout << (sum - (n - 1)) << "\n";
    }
    
    return 0;
}
