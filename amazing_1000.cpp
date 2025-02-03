#include <bits/stdc++.h>
using namespace std;

bool isPrime(int num){
for(int i = 2;i*i<=num;i++){
    if(num%i==0){
        return false;
    }
}
return true;
}
int next_prime(int x){
    for(int num = x;;num++){
        if(isPrime(num)){
            return num;
        }
    }
    return -1;
}
void solve(){
  int d;
  cin>>d;

  int p = next_prime(d+1);
  int q = next_prime(p+d);

  cout<<min(1LL*p*p*p, 1LL*p*q)<<endl;

}
int main() {
    int t;
    cin>>t;
    while(t--){
     solve();
    }
    return 0;
}
