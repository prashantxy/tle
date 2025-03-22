#include <iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while(t--){
        int n;
        long long k;
        cin >> n >> k;
        int grid[1005][1005];
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                cin >> grid[i][j];
            }
        }
        int mismatches = 0;
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                int si = n - 1 - i;
                int sj = n - 1 - j;
                if(i < si || (i == si && j <= sj)){
                    if(i == si && j == sj)
                        continue;
                    if(grid[i][j] != grid[si][sj])
                        mismatches++;
                }
            }
        }
        if(k < mismatches){
            cout << "NO\n";
            continue;
        }
        long long extra = k - mismatches;
        if(extra % 2 == 0){
            cout << "YES\n";
        } else {
            if(n % 2 == 1)
                cout << "YES\n";
            else
                cout << "NO\n";
        }
    }
    
    return 0;
}
