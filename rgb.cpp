#include <bits/stdc++.h>
using namespace std;

int main() {
    long long r, g, b;
    cin >> r >> g >> b;
    
    long long sum = r + g + b;
    long long maxColor = max({r, g, b});
      
    long long tables = min(sum / 3, sum - maxColor);
    cout << tables<<endl;
       
    return 0;
}
