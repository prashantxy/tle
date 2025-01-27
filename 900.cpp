#include <iostream>
#include <set>
using namespace std;

int count_knight_forks(int a, int b, int xK, int yK, int xQ, int yQ) {
   
    int moves[8][2] = {
        {a, b}, {a, -b}, {-a, b}, {-a, -b},
        {b, a}, {b, -a}, {-b, a}, {-b, -a}
    };

    set<pair<int, int>> candidates;
    for (int i = 0; i < 8; i++) {
        int x = xK - moves[i][0];
        int y = yK - moves[i][1];
        candidates.insert({x, y});
    }

    int count = 0;
    for (auto &[x, y] : candidates) {
        for (int i = 0; i < 8; i++) {
            if (x + moves[i][0] == xQ && y + moves[i][1] == yQ) {
                count++;
                break;
            }
        }
    }

    return count;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    
    while (t--) {
        int a, b, xK, yK, xQ, yQ;
        cin >> a >> b >> xK >> yK >> xQ >> yQ;
        cout << count_knight_forks(a, b, xK, yK, xQ, yQ) << '\n';
    }

    return 0;
}
