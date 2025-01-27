#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int>arr(n);
        vector<int>arr1(n);
        for(int i = 0;i<n;i++){
            cin>>arr[i];
        }
        for(int i = 0;i<n;i++){
            cin>>arr1[i];
        }
        int difference1 = 0;
        int difference2 = 0;
        for(int i = 0;i<n;i++){
            if(arr[i]<arr1[i]){
               
                 difference1 += arr1[i]-arr[i];
            }
            else{
                 difference2 += arr[i]-arr1[i];
            }
        }
        int a = n-1;
        long long  b = difference2/a;
        if(difference1<=b){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
    }
    return 0;
}