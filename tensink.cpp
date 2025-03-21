#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while(t--){
        int n;
        ll x;
        cin >> n >> x;
        vector<ll> A(n), B(n), C(n);
        for (int i = 0; i < n; i++) cin >> A[i];
        for (int i = 0; i < n; i++) cin >> B[i];
        for (int i = 0; i < n; i++) cin >> C[i];
        
        ll cur = 0;
        int iA = 0, iB = 0, iC = 0;
        bool progress = true;
        
        while(progress && cur != x){
            progress = false;
            // Check stack A
            while(iA < n){
                ll candidate = A[iA];
                ll new_val = cur | candidate;
                if(((cur | candidate) & (~x)) != 0) break; 
                iA++; 
                if(new_val != cur){
                    cur = new_val;
                    progress = true;
                    break;
                }
            }
            if(progress || cur == x) continue;
            // Check stack B
            while(iB < n){
                ll candidate = B[iB];
                ll new_val = cur | candidate;
                if(((cur | candidate) & (~x)) != 0) break;
                iB++;
                if(new_val != cur){
                    cur = new_val;
                    progress = true;
                    break;
                }
            }
            if(progress || cur == x) continue;
            // Check stack C
            while(iC < n){
                ll candidate = C[iC];
                ll new_val = cur | candidate;
                if(((cur | candidate) & (~x)) != 0) break;
                iC++;
                if(new_val != cur){
                    cur = new_val;
                    progress = true;
                    break;
                }
            }
        }
        cout << (cur == x ? "Yes" : "No") << "\n";
    }
    return 0;
}
