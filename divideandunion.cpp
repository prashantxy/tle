#include<bits/stdc++.h>

using namespace std;

#define x first
#define y second

typedef pair<int, int> pt;

int n;
vector< pair<pt, int> > segs;

inline bool read() {
	if(!(cin >> n))
		return false;
	segs.resize(n);
	for(int i = 0; i < n; i++) {
		cin >> segs[i].x.x >> segs[i].x.y;
		segs[i].y = i;
	}
	return true;
}

bool cmp(const pair<pt, int> &a, const pair<pt, int> &b) {
	if(a.x.y != b.x.y)
		return a.x.y < b.x.y;
	if(a.x.x != b.x.x)
		return a.x.x < b.x.x;
	return a.y < b.y;
}
// if two segments then ans.
// ekse -1;
inline void solve() {
	sort(segs.begin(), segs.end(), cmp);
	
	int mn = segs[n - 1].x.x;
	for(int i = n - 2; i >= 0; i--) {
		if(segs[i].x.y < mn) {
			vector<int> ts(n, 2);
			for(int id = 0; id <= i; id++)
				ts[segs[id].y] = 1;
			
			for(int t : ts)
				cout << t << ' ';
			cout << '\n';
				
			return;
		}
		mn = min(mn, segs[i].x.x);
	}
	cout << -1 << '\n';
}

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	int tt = clock();
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cout << fixed << setprecision(15);
	
	int tc;
	cin >> tc;
	
	while(tc--) {
		assert(read());
		solve();
		
#ifdef _DEBUG
		cerr << "TIME = " << clock() - tt << endl;
		tt = clock();
#endif
	}
	return 0;
}