#include <bits/stdc++.h>
using namespace std;

void solve(){
    int t;
    cin >> t;
    while(t--) {
        int n, q;
        cin >> n >> q; 
        
        vector<int> arr(n);
        long long sum = 0;
     
        for(int i = 0; i < n; i++) {
            cin >> arr[i];
            sum += arr[i];
        }
        
      
        while(q--) {
            int l, r, k;
            cin >> l >> r >> k;
            
            
            l--; r--;
            
            
            int count = r - l + 1;
            
            // If k is odd, flipping the parity of the range affects the sum
            if(k % 2 == 1) {
                // If the count of elements in the range is odd, toggle the parity
                if(count % 2 == 1) {
                    // Toggle parity of the whole sum 
                    sum = sum % 2 == 0 ? sum + count * k : sum - count * k;
                }
            }
            if(sum % 2 == 1)
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
        }
    }
}

int main(){
    solve();
    return 0;
}
