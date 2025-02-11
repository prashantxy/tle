#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool isSorted(vector<int>arr){
    for(int i = 0;i<n-1;i++){
        if(arr[i]>arr[i+1]){
            return false;
        }
    }
}
void solve() {
    int n;
    cin >> n;
    vector<int> arr(n);
    vector<int> arr1(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> arr1[i];
    }

 
    if (isSorted(arr) == arr && isSorted(arr1) == arr1){
        cout << "YES" << endl;
    }
    else {
       
        if (arr == arr1) {
            cout << "YES" << endl;
        }
        else {
            cout << "NO" << endl;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}
