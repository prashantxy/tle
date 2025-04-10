#include <bits/stdc++.h>
using namespace std;
bool canPartition(const vector<int>& a, int total) {
    int target = total / 2;
    int n = a.size();
    vector<bool> dp(target + 1, false);
    dp[0] = true; 
    for (int i = 0; i < n; i++) {
        for (int s = target; s >= a[i]; s--) {
            if(dp[s - a[i]])
                dp[s] = true;
        }
    }
    return dp[target];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    vector<int> a(n);
    int total = 0;
    for (int i = 0; i < n; i++){
        cin >> a[i];
        total += a[i];
    }
    if(total % 2 == 1){
        cout << 0 << "\n";
        return 0;
    }
    if(!canPartition(a, total)){
        cout << 0 << "\n";
        return 0;
    }
    
    int indexToRemove = -1;
    int minDivisions = 1e9; 
    for (int i = 0; i < n; i++){
        int x = a[i];
        int cnt = 0;
        while(x % 2 == 0){
            cnt++;
            x /= 2;
        }
        if(cnt < minDivisions){
            minDivisions = cnt;
            indexToRemove = i;
        }
    }
    cout << 1 << "\n";
    cout << (indexToRemove + 1) << "\n";
    
    return 0;
}
