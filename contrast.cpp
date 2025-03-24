#include <bits/stdc++.h>
using namespace std;
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++){
            cin >> a[i];
        }
        if(n <= 1){
            cout << n << "\n";
            continue;
        }
        vector<int> b;
        b.push_back(a[0]);
        int last_sign = 0;
        for (int i = 1; i < n; i++){
            int diff = a[i] - a[i-1];
            if(diff == 0){
                continue;
            }
            int sign = (diff > 0) ? 1 : -1;
            if(last_sign == 0){
                last_sign = sign; 
            }
            else if(sign != last_sign){
                if(b.back() != a[i-1])
                    b.push_back(a[i-1]);
                last_sign = sign;
            }
        }
        b.push_back(a[n-1]);
        if(b.size() == 2 && b[0] == b[1])
            cout << 1 << "\n";
        else
            cout << b.size() << "\n";
    }
    return 0;
}
