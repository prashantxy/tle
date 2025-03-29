#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

const int MAXN = 100005;

int par[MAXN], c[MAXN], countRespect[MAXN];
vector<int> children[MAXN];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    int root = -1;
    for (int i = 1; i <= n; i++){
        cin >> par[i] >> c[i];
        if(par[i] == -1){
            root = i;
        } else {
            children[par[i]].push_back(i);
        }
    }
    for (int i = 1; i <= n; i++){
        if(par[i] != -1 && c[i] == 0){
            countRespect[ par[i] ]++;
        }
    }
    auto isCandidate = [&](int v) -> bool {
        return (v != root && c[v] == 1 && countRespect[v] == 0);
    };
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int v = 1; v <= n; v++){
        if(isCandidate(v))
            pq.push(v);
    }
    
    vector<int> deletionOrder;
    
    while(!pq.empty()){
        int v = pq.top();
        pq.pop();
        if(!isCandidate(v))
            continue;
        
        deletionOrder.push_back(v);
        int p = par[v];  
        for (int w : children[v]){
            par[w] = p;
            children[p].push_back(w);
            if(c[w] == 0)
                countRespect[p]++;
        }
        children[v].clear();
        if(p != root && isCandidate(p))
            pq.push(p);
    }
    
    if(deletionOrder.empty()){
        cout << -1 << "\n";
    } else {
        for (int v : deletionOrder)
            cout << v << " ";
        cout << "\n";
    }
    
    return 0;
}
