#include <bits/stdc++.h>
using namespace std;

struct Candidate {
    long long value;
    int index;
};
void updateTop(Candidate cand, Candidate top[3]) {
    if (cand.value > top[0].value) {
        top[2] = top[1];
        top[1] = top[0];
        top[0] = cand;
    } else if (cand.value > top[1].value) {
        top[2] = top[1];
        top[1] = cand;
    } else if (cand.value > top[2].value) {
        top[2] = cand;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<long long> a(n), b(n), c(n);
        for (int i = 0; i < n; i++){
            cin >> a[i];
        }
        for (int i = 0; i < n; i++){
            cin >> b[i];
        }
        for (int i = 0; i < n; i++){
            cin >> c[i];
        }
        Candidate topA[3] = { { -1, -1 }, { -1, -1 }, { -1, -1 } };
        Candidate topB[3] = { { -1, -1 }, { -1, -1 }, { -1, -1 } };
        Candidate topC[3] = { { -1, -1 }, { -1, -1 }, { -1, -1 } };
        
      
        for (int i = 0; i < n; i++){
            updateTop({a[i], i}, topA);
        }
    
        for (int i = 0; i < n; i++){
            updateTop({b[i], i}, topB);
        }
        // Process array c.
        for (int i = 0; i < n; i++){
            updateTop({c[i], i}, topC);
        }
        
        long long maxSum = 0;
        
        for (int i = 0; i < 3; i++){
            for (int j = 0; j < 3; j++){
                for (int k = 0; k < 3; k++){
                    int idxA = topA[i].index, idxB = topB[j].index, idxC = topC[k].index;
                    if (idxA != idxB && idxA != idxC && idxB != idxC) {
                        long long currentSum = topA[i].value + topB[j].value + topC[k].value;
                        maxSum = max(maxSum, currentSum);
                    }
                }
            }
        }
        cout << maxSum << "\n";
    }
    return 0;
}
