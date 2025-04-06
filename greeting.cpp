#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

struct Person {
    ll a, b;
};

struct Fenwick {
    vector<ll> tree;
    int n;
    Fenwick(int n): n(n) {
        tree.assign(n + 1, 0);
    }
    void update(int idx, ll val) {
        for(; idx <= n; idx += idx & (-idx))
            tree[idx] += val;
    }
    ll query(int idx) {
        ll sum = 0;
        for(; idx > 0; idx -= idx & (-idx))
            sum += tree[idx];
        return sum;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<Person> people(n);
        vector<ll> bs;
        
        for (int i = 0; i < n; i++) {
            cin >> people[i].a >> people[i].b;
            bs.push_back(people[i].b);
        }
        sort(bs.begin(), bs.end());
        bs.erase(unique(bs.begin(), bs.end()), bs.end());
        
        auto getIndex = [&](ll x) -> int {
            return (int)(lower_bound(bs.begin(), bs.end(), x) - bs.begin()) + 1; 
        };

        sort(people.begin(), people.end(), [](const Person &p1, const Person &p2) {
            return p1.a < p2.a;
        });
        
        Fenwick fenw(bs.size());
        ll greetings = 0;
        for (auto &p : people) {
            int idx = getIndex(p.b);
            ll greaterCount = fenw.query(bs.size()) - fenw.query(idx);
            greetings += greaterCount;
            fenw.update(idx, 1);
        }
        
        cout << greetings << "\n";
    }
    
    return 0;
}
