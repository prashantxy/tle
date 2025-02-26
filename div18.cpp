#include <bits/stdc++.h>
using namespace std;

bool isValid(int n, vector<int>& b) {
    vector<int> a(n, -1); 

    
    for (int i = 1; i < n - 1; i++) {
        if (b[i - 1] == 1) {
            if (a[i] == -1) a[i] = a[i - 1] = a[i + 1] = 1; 
            else if (a[i] != a[i - 1] || a[i] != a[i + 1]) return false;
        } 
        if (b[i - 1] == 0) {
            if (a[i] == -1) a[i] = a[i - 1] ^ 1; 
            else if (a[i] == a[i - 1] && a[i] == a[i + 1]) return false;
        }
    }
    
    return true;
}

int main() {
    int t;
    cin >> t;  
    while (t--) {
        int n;
        cin >> n;
        vector<int> b(n - 2);  
        for (int i = 0; i < n - 2; i++) cin >> b[i];

        cout << (isValid(n, b) ? "YES" : "NO") << endl;
    }
    return 0;
}
