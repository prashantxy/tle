#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main() 
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    
	    vector<int> v(n);
	    int maxi=-1e9;
	    map<int,int> map;
	    for(int i=0;i<n;i++)
	    {
	        cin>>v[i];
	        map[v[i]]++;
	        maxi=max(maxi,map[v[i]]);
	        
	    }
	    
	    if(maxi==n)
	    {
	        cout<<"0"<<endl;
	        continue;
	    }
	    
	   
	    int num=n-maxi;
	    int op=0;
	    int cnt=maxi;
	    while(num>0)
	    {
	        
	        op++;
	        op+= num>cnt?cnt:num;
	        num-=cnt;
	        cnt*=2;
	    }
	    
	    cout<<op<<endl;
	}
	return 0;
}

