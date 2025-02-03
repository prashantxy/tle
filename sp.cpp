#include <bits/stdc++.h>
using namespace std;
 
void solve() {
   int n,k;
   cin>>n>>k;
   string s;
   cin>>s;
   int i = 0;
   int j = 0;
   int mini = n;
   int whites = 0;
   while(j<n){
    if(s[j]=='W'){  //chutiya hu mai j aayega slide toh yeah hi ho rahi hai na
        whites++;
    }
    if(j-i+1<k){
     j++;
     continue;
    }
    mini = min(whites,mini);
    j++;
    if(s[i]=='W'){ 
        whites--;
    }
    i++;
   }
   cout<<mini<<endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
