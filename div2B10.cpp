#include <iostream>
#include <vector>
using namespace std;
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        vector<int> a(n+1, 0);  
        if(k % 2 == 1) {
            for (int i = 1; i < n; i++){
                a[i] = n;
            }
            a[n] = n - 1;
        } else {
            for (int i = 1; i <= n - 2; i++){
                a[i] = n - 1;
            }
            a[n - 1] = n;
            a[n] = n - 1;
        }
 
     
        for (int i = 1; i <= n; i++){
            cout << a[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}
