    #include <bits/stdc++.h>
    #define ll long long int
    #define nline '\n'
    using namespace std;
     
    void solve()
    {
        ll a, b, c;
        cin >> a >> b >> c;
     
        if ((b - a) == (c - b))
            cout << "YES" << nline;

        // Checking For A
        else if ((2 * b - c) % a == 0 && (2 * b - c) > 0)
            cout << "YES" << nline;

        // Checking For B
        else if ((a + c) % (2 * b) == 0)
            cout << "YES" << nline;

        // Checking For C
        else if ((2 * b - a) % c == 0 && (2 * b - a) > 0)
            cout << "YES" << nline;

        else
            cout << "NO" << nline;
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
        }
  }