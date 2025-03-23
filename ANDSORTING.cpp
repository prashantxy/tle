#include <bits/stdc++.h>
using namespace std;

bool checkCandidate(int X, const vector<int>& p, const vector<int>& B) {
    int n = p.size();
    vector<int> frozenP, frozenB;
    int movableCount = 0;
    
    for (int i = 0; i < n; i++){
        if ((p[i] & X) == X) {
            movableCount++;
        } else {
            frozenP.push_back(p[i]);
        }
    }
    for (int i = 0; i < n; i++){
        if ((B[i] & X) != X)
            frozenB.push_back(B[i]);
    }
    if (frozenP != frozenB)
        return false;
    if (movableCount < 2)
        return false;
    
    return true;
}
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t; 
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> p(n);
        for (int i = 0; i < n; i++){
            cin >> p[i];
        }
        vector<int> B = p;
        sort(B.begin(), B.end());
        int candidate = 0;
        for (int bit = 31; bit >= 0; bit--){
            int newCandidate = candidate | (1 << bit);
            if (checkCandidate(newCandidate, p, B))
                candidate = newCandidate;
        }
 
        cout << candidate << "\n";
    }
    
    return 0;
}
