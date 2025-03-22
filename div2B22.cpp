#include <iostream>
#include <vector>
using namespace std;

// Function to compute mex of a segment [l, r] in the vector v
// (We assume the numbers are at most n, so we use a small frequency array.)
int compute_mex(const vector<int>& v, int l, int r) {
    // Since values are between 0 and n (n<=5000), a fixed-size boolean array is safe.
    int n = v.size();
    vector<bool> present(n+2, false);
    for (int i = l; i <= r; i++){
        if(v[i] < (int)present.size())
            present[v[i]] = true;
    }
    int mex = 0;
    while(present[mex]) mex++;
    return mex;
}

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
        vector<pair<int,int>> ops;
        auto doOp = [&](int l, int r) {
            int L = l-1, R = r-1;
            int newVal = compute_mex(a, L, R);
            vector<int> newA;
            for (int i = 0; i < L; i++){
                newA.push_back(a[i]);
            }
            newA.push_back(newVal);
            for (int i = R+1; i < (int)a.size(); i++){
                newA.push_back(a[i]);
            }
            a = newA;
            ops.push_back({l, r});
        };
        bool has0 = false;
        for (int x : a){
            if(x == 0){
                has0 = true;
                break;
            }
        }
        if(!has0){
            doOp(1, a.size());
        }
        else {
            while(a.size() > 2) {
                bool found0 = false;
                for (int i = 0; i < (int)a.size(); i++){
                    if(a[i] == 0) {
                        found0 = true;
                        if(i > 0) {
                            doOp(i, i+1);
                        } else {
                            doOp(1, 2);
                        }
                        break; 
                    }
                }
                if(!found0) break; 
            }
            while(a.size() > 1) {
                bool contains0 = false;
                for (int x : a) {
                    if(x == 0) { contains0 = true; break; }
                }
                if(!contains0) {
                    doOp(1, a.size());
                } else {
                    break;
                }
            }
        }
        cout << ops.size() << "\n";
        for (auto &op : ops){
            cout << op.first << " " << op.second << "\n";
        }
    }
    return 0;
}
