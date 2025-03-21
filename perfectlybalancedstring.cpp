#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
using namespace std;

bool isPerfectlyBalanced(const string &s) {
    string pattern;
    unordered_set<char> seen;
     
    for (char ch : s) {
        if (seen.find(ch) == seen.end()) {
            seen.insert(ch);
            pattern.push_back(ch);
        }
    }
    
    int pSize = pattern.size();
    int n = s.size();
    for (int i = 0; i < n; i++) {
        if (s[i] != pattern[i % pSize]) //comparing with each other
            return false;
    }
    
    return true;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        cout << (isPerfectlyBalanced(s) ? "YES" : "NO") << "\n";
    }
    return 0;
}
