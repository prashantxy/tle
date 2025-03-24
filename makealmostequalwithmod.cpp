#include <iostream>
#include <vector>
using namespace std;
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    const long long LL = 1000000000000000000LL;
    while(t--){
        int n;
        cin >> n;
        vector<long long> a(n);
        for (int i = 0; i < n; i++){
            cin >> a[i];
        }
        if(n == 2){
            long long kCandidate = LL;
            long long r0 = a[0] % kCandidate;
            long long r1 = a[1] % kCandidate;
            if(r0 == 0 || r1 == 0){
                cout << LL << "\n";
            } else {
                cout << kCandidate << "\n";
            }
            continue;
        }
        bool hasEven = false, hasOdd = false;
        for (int i = 0; i < n; i++){
            if(a[i] % 2 == 0) 
                hasEven = true;
            else 
                hasOdd = true;
        }
        if(hasEven && hasOdd){
            cout << 2 << "\n";
            continue;
        }
        bool found = false;
        for(long long k = 2; k < 10000; k++){
            long long r0 = -1, r1 = -1;
            bool valid = true;
            int distinctCount = 0;
            for (int i = 0; i < n; i++){
                long long r = a[i] % k;
                if(r0 == -1){
                    r0 = r;
                    distinctCount++;
                } else if(r == r0){
                  
                } else if(r1 == -1){
                    r1 = r;
                    distinctCount++;
                } else if(r == r1){
                  
                } else {
                    valid = false;
                    break;
                }
            }
            if(valid && distinctCount == 2){
                cout << k << "\n";
                found = true;
                break;
            }
        }
        if(!found){
            cout << LL << "\n";
        }
    }
    return 0;
}
