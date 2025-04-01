#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    long long k, x;
    cin >> n >> k >> x;
    vector<long long> levels(n);
    for (int i = 0; i < n; i++){
        cin >> levels[i];
    }
    
    sort(levels.begin(), levels.end());
    vector<long long> gaps;
    for (int i = 1; i < n; i++){
        long long diff = levels[i] - levels[i-1];
        if(diff > x){
            long long needed = (diff + x - 1) / x - 1;
            gaps.push_back(needed);
        }
    }
    int groups = gaps.size() + 1;
    sort(gaps.begin(), gaps.end());
    
    for(auto needed : gaps) {
        if(k >= needed){
            k -= needed;
            groups--; 
        } else {
            break;
        }
    }
    
    cout << groups << "\n";
    return 0;
}
