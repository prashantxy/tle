#include <bits/stdc++.h>
using namespace std;

#define Code ios_base::sync_with_stdio(false);
#define By cin.tie(NULL);
#define pdubey1924_macro cout.tie(NULL);
#define fl(i, n) for (int i = 0; i < n; i++)

const int N = 200 * 1000 + 13;
const int LOGN = 30;

int n;
int a[N], pr[N];
int base[LOGN];

void try_gauss(int v) {
    for (int i = LOGN - 1; i >= 0; i--)
        if (base[i] != -1 && (v & (1 << i)))
            v ^= base[i];
    if (v == 0)
        return;
    for (int i = LOGN - 1; i >= 0; i--)
        if (v & (1 << i)) {
            base[i] = v;
            return;
        }
}

int main(){
    Code By pdubey1924_macro
    cin >> n;
    fl(i, n)
        cin >> a[i];
    memset(base, -1, sizeof(base));
    pr[0] = 0;
    fl(i, n){
        pr[i + 1] = pr[i] ^ a[i];
        try_gauss(pr[i + 1]);
    }
    if (pr[n] == 0){
        cout << -1 << "\n";
        return 0;
    }
    int siz = 0;
    fl(i, LOGN)
        siz += (base[i] != -1);
    cout << siz << "\n";
    return 0;
}
