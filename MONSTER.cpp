#include <bits/stdc++.h>
#define ll long long int
#define nline '\n'
using namespace std;

void solve()
{
    ll n, k;
    cin >> n >> k;

    vector<ll> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    vector<pair<ll, ll>>pair_indices;  //to store th eoriginal valuue kyuki last mai original indices nahi lost hone chahiye
    for (int i = 0; i < n; i++)
    {
        ll res = arr[i] % k;
        if (res == 0)
            res += k;
            pair_indices.push_back({-res, i});     //here
    }
    sort(pair_indices.begin(), pair_indices.end());
    for (auto el : pair_indices)
        cout << el.second + 1 << " ";   //one - based indexing

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll T = 1;
    cin >> T;
    while (T--) 
    {
           solve();
           cout<<endl;
    }

}