#include <iostream>
#include <vector>
#include <queue>
using namespace std;
using ll = long long;
const ll MOD = 998244353;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
     
        vector<int> parent(n+1, 0);
        vector<vector<int>> children(n+1);
        for (int i = 2; i <= n; i++){
            cin >> parent[i];
            children[parent[i]].push_back(i);
        }
        vector<int> depth(n+1, 0);
        queue<int> q;
        q.push(1);
        depth[1] = 0;
        int max_depth = 0;
        while(!q.empty()){
            int cur = q.front();
            q.pop();
            for (int nxt : children[cur]){
                depth[nxt] = depth[cur] + 1;
                max_depth = max(max_depth, depth[nxt]);
                q.push(nxt);
            }
        }
        vector<ll> X(max_depth+1, 0);
        for (int i = 2; i <= n; i++){
            X[depth[i]]++;
        }
        vector<ll> A(max_depth+2, 0); 
        for (int d = max_depth; d >= 1; d--){
            A[d] = ( X[d] + ((X[d] - 1) % MOD + MOD) % MOD * A[d+1] ) % MOD;
        }
        ll ans = (1 + A[1]) % MOD;
        cout << ans % MOD << "\n";
    }
    return 0;
}
