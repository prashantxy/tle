#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        vector<string> matrix(n);
        for (int i = 0; i < n; i++){
            cin >> matrix[i];
        }
        
        int odd_rows = 0;
        for (int i = 0; i < n; i++){
            int cnt = 0;
            for (int j = 0; j < m; j++){
                if(matrix[i][j] == '1'){
                    cnt++;
                }
            }
            if(cnt % 2 == 1)
                odd_rows++;
        }
        
        int odd_cols = 0;
        for (int j = 0; j < m; j++){
            int cnt = 0;
            for (int i = 0; i < n; i++){
                if(matrix[i][j] == '1'){
                    cnt++;
                }
            }
            if(cnt % 2 == 1)
                odd_cols++;
        }
        
        cout << max(odd_rows, odd_cols) << "\n";
    }
    
    return 0;
}
