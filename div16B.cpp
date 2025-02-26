#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> arr(n);
    map<int, int> freq;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        freq[arr[i]]++;
    }

    if(n==1){
        cout<<1<<" "<<1<<endl;
        return;
    }
    int cnt = 0;
    if (freq.size() == 1) {
        cout << "0\n";
        return;
    }

    int max_freq = 0, element = -1;
    for (auto it : freq) {
        if (it.second > max_freq) {
            max_freq = it.second;
            element = it.first;
        }
    }

    int first_occur = -1, last_occur = -1;

    for (int i = 0; i < n; i++) {
        if (arr[i] != element) {   
            if (first_occur == -1&&cnt!=0) first_occur = i; 
        }
        else{
            cnt++;
        }
    }
    int cnt1 = 0;
    for (int i = n-1; i >=0; i--) {
        if (arr[i] != element) {
            if (last_occur == -1&&cnt1!=0) last_occur = i;
        }
        else{
            cnt1++;
        }
    }
    cout << first_occur + 1 << " " << last_occur + 1 << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
