#include <bits/stdc++.h>
using namespace std;

void solve(int i, int j, vector<vector<string>>& path, int n,  long long int move, vector<vector<int>>& vis, vector<vector<int>>& strength, long long int& maxMove, long long int k) {
    if (i == n - 1 && j == n - 1) {
        maxMove = max(maxMove, move); 
        return;
    }

    vis[i][j] = 1;


    if (i + 1 < n && !vis[i + 1][j] && path[i + 1][j] == 1 && k >= strength[i + 1][j]) {
        solve(i + 1, j, path, n, move + strength[i + 1][j], vis, strength, maxMove, k - stoi(path[i + 1][j]));
    }

    
    if (j - 1 >= 0 && !vis[i][j - 1] && path[i][j - 1] == 1 && k >= strength[i][j - 1]) {
        solve(i, j - 1, path, n, move + strength[i][j - 1], vis, strength, maxMove, k - stoi(path[i + 1][j]));
    }


    if (j + 1 < n && !vis[i][j + 1] && path[i][j + 1] == 1 && k >= strength[i][j + 1]) {
        solve(i, j + 1, path, n, move + strength[i][j + 1], vis, strength, maxMove, k - stoi(path[i + 1][j]));
    }

    
    if (i - 1 >= 0 && !vis[i - 1][j] && path[i - 1][j] == 1 && k >= strength[i - 1][j]) {
        solve(i - 1, j, path, n, move + strength[i - 1][j], vis, strength, maxMove, k - stoi(path[i + 1][j]));
    }

    vis[i][j] = 0; 
}

long long int findPath(vector<vector<>>& path, vector<vector<int>>& strength, long long int k) {
    int n = path.size();
    if (path[0][0] == 0 || path[n - 1][n - 1] == 0) return 0;

    vector<vector<int>> vis(n, vector<int>(n, 0));
    long long int maxMove = 0;
    
    solve(0, 0, path, n, strength[0][0], vis, strength, maxMove, k - path[0][0]);
    return maxMove;
}

int main() {
    
  
        int n, m;
        cin >> n >> m;
        vector<vector<string>> path(n, vector<string>(m));
        vector<vector<int>> strength(n, vector<int>(m));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> path[i][j];
            }
        }
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> strength[i][j];
            }
        }

        long long int k;
        cin >> k;

        cout << findPath(path, strength, k) << " ";
        cout << k<<" ";

    return 0;
}