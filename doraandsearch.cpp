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
        int left = 0, right = n - 1;
        int currentMin = 1, currentMax = n;
        while(left < right){
            if(a[left] == currentMin) {
                ++left;
                ++currentMin;
            }
            else if(a[right] == currentMin) {
                --right;
                ++currentMin;
            }
            else if(a[left] == currentMax) {
                ++left;
                --currentMax;
            }
            else if(a[right] == currentMax) {
                --right;
                --currentMax;
            }
            else {
                break;
            }
        }
        if(left < right)
            cout << left + 1 << " " << right + 1 << "\n";  
        else
            cout << -1 << "\n";
    }
    
    return 0;
}
