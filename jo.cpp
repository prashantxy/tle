#include<bits/stdc++.h>
using namespace std;

void solve(){
int t;
cin>>t;
while(t--){
long long n,m;
		cin>>n>>m;
		if(m>n)
			swap(n,m);
		long long ans=n/m;
		if((ans&(ans-1))|| n%m)  //checking whether it is power of 2 or not ;;;;
			cout<<-1<<endl;
		else
		{
			ans=ceil(log2(ans)/3); 
			cout<<ans<<endl;
		}

}
}
int main(){
solve();
return 0;
}
