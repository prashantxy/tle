#include <bits/stdc++.h>
using namespace std;

void solve() {
    long long a, b;
    cin >> a >> b;
    long long min_operations = 1e9;

    for (int i = 0; i < 30; i++) {  
        long long new_a =a;
        if(b+i >= 2){
            long long turns = i;
            while(new_a>0){
                new_a/=(b+i);
                turns++;
            }
        
        min_operations = min(min_operations,turns);
        }

    }

    cout << min_operations << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
