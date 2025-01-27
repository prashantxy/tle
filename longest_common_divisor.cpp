#include<iostream>
using namespace std;


   void solve(){
    long int t, N;
    cin >> t;

    while(t--)
    {
        long long n;
        cin>>n;
        long long maxi = 0;
        long long cnt = 0;
        for(long long i = 1;i<=10000;i++){
          if(n/i==0){
            break;
          }
          else if(n%i==0){
              cnt++;
          }
          else{
            cnt = 0;
          }
           maxi = max(maxi,cnt);
        }
        cout<<maxi<<endl;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}