#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> Interval;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        vector<ll> centers(n);
        vector<ll> radii(n);
        
        for (int i = 0; i < n; i++){
            cin >> centers[i];
        }
        
        ll sumR = 0;
        ll maxR = 0;
        
        for (int i = 0; i < n; i++){
            cin >> radii[i]; 
            sumR += radii[i];
            maxR = max(maxR, radii[i]);
        }
        
        ll offset = maxR; 
        vector<vector<Interval>> rowIntervals(2 * maxR + 1); 
        
        for (int i = 0; i < n; i++){
            ll r = radii[i];
            ll cx = centers[i];
            for (ll y = -r; y <= r; y++){
                ll dy2 = y * y;
                ll rem = r * r - dy2;
                if (rem < 0) continue; 
                ll d = (ll) floor(sqrt((double) rem));
                ll L = cx - d;
                ll R = cx + d;
                rowIntervals[y + offset].push_back({L, R});
            }
        }
        
        ll totalPoints = 0;
        for (int y = 0; y < (int) rowIntervals.size(); y++){
            if(rowIntervals[y].empty()) continue;
            sort(rowIntervals[y].begin(), rowIntervals[y].end(), [](const Interval &a, const Interval &b){
                return a.first < b.first;
            });
            
            Interval cur = rowIntervals[y][0];
            ll rowCount = 0;
            
            for (size_t j = 1; j < rowIntervals[y].size(); j++){
                Interval nxt = rowIntervals[y][j];
                if(nxt.first <= cur.second + 1) {
                    cur.second = max(cur.second, nxt.second);
                } else {
                    rowCount += (cur.second - cur.first + 1);
                    cur = nxt;
                }
            }
            rowCount += (cur.second - cur.first + 1);
            totalPoints += rowCount;
        }
        
        cout << totalPoints << "\n";
    }
    
    return 0;
}
