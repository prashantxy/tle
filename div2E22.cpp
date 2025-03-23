#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define fastIO ios_base::sync_with_stdio(false); cin.tie(nullptr);
using ll = long long;

void solveTestCase() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i=0; i<n; i++){
        cin >> a[i];
    }
    for (int i=0; i<n; i++){
        cin >> b[i];
    }
    vector<int> sortedB = b;
    sort(sortedB.begin(), sortedB.end());
    if(n == 1) {
        if(a[0] == b[0]) {
            
            cout << a[0] + 1 << "\n";
            return;
        }
        for (int k = b[0] + 1; k <= a[0]; k++) {
            if(a[0] % k == b[0]) { 
                cout << k << "\n";
                return;
            }
        }
        cout << -1 << "\n";
        return;
    }
    int maxB = *max_element(b.begin(), b.end());
    int kLow = maxB + 1;
    int maxA = *max_element(a.begin(), a.end());
    if(kLow > maxA) {
        vector<int> sortedA = a;
        sort(sortedA.begin(), sortedA.end());
        if(sortedA == sortedB) {
            cout << kLow << "\n";  
            return;
        } else {
            cout << -1 << "\n";
            return;
        }
    }
    for (int k = kLow; k <= maxA + 1; k++) {
        vector<int> rem;
        rem.reserve(n);
        for (int i = 0; i < n; i++){
            rem.push_back(a[i] % k);
        }
        sort(rem.begin(), rem.end());
        if(rem == sortedB) {
            cout << k << "\n";
            return;
        }
    }
    cout << -1 << "\n";
}

int main(){
    fastIO;
    int t;
    cin >> t;
    while(t--) {
        solveTestCase();
    }
    return 0;
}
