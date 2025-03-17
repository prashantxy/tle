#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n,x;
  cin>>n>>x;
  int num=0;
  for(int i=0;i<30;i++){
    if(((x>>i)&1)==0){
      break;
    }
    num=num<<1;
    num+=1;
  }
  std::vector<int> arr;
  int count=0;
  int curr=0;
  for(int i=0;i<n;i++){
    if(i==n-1){
      if((curr|count)==x){
        arr.push_back(count);
      }else{
        arr.push_back(x);
      }
      break;
    }
    arr.push_back(count);
    curr=curr|count;
    if(count!=num){
      count++;      
    }
  }
  for(int i:arr){
    cout<<i<<" ";
  }
  cout<<endl;

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
