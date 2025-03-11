#include <bits/stdc++.h>
using namespace std;
#define BIT(i) (1LL << (i))
#define IS_POWER_OF_2(n) (((n) & ((n) - 1)) == 0)
#define MSB(x) (31 - __builtin_clz((unsigned int)(x)))

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while(t--){
        long long x;
        cin >> x;
        if(IS_POWER_OF_2(x)){
            cout << -1 << "\n";
            continue;
        }
        int m = MSB(x);
        long long allOnes = BIT(m + 1) - 1;
        if(x == allOnes){
            cout << -1 << "\n";
            continue;
        }
        long long ans = -1;
        for (int i = 0; i <= m; i++){
            if(x & BIT(i)){
                for (int j = 0; j <= m; j++){
                    if(i == j) continue;
                    if(!(x & BIT(j))){
                        long long candidate = BIT(i) + BIT(j);  //dekhna hai calculated XOR by cancellation x&y >0  
                                                              //x>x&y
                                                               // y>x&y
                        if(candidate < x){
                            ans = candidate;
                            break;
                        }
                    }
                }
                if(ans != -1) break;
            }
        }
 
        cout << ans << "\n";
    }
    return 0;
}
