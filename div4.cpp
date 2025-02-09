#include <bits/stdc++.h>
using namespace std;

void solve() {
int n, m;
cin >> n >> m;
vector<int> a(n);
for (int &x : a) cin >> x;

vector<int> b(m);
for (int &x : b) cin >> x;
int b1 = b[0];

vector<int> f(n);
for (int i = 0; i < n; ++i) {
f[i] = b1 - a[i];
}

if (n == 1) {
cout << "YES\n";
return;
}
bool prev_keep = true, prev_flip = true;
for (int i = 1; i < n; ++i) {
bool current_keep = false;
bool current_flip = false;
if (prev_keep) {
if (a[i] >= a[i-1]) {
current_keep = true;
}
if (f[i] >= a[i-1]) {
current_flip = true;
}
}
if (prev_flip) {
if (a[i] >= f[i-1]) {
current_keep = true;
}
if (f[i] >= f[i-1]) {
current_flip = true;
}
}
prev_keep = current_keep;
prev_flip = current_flip;
if (!prev_keep && !prev_flip) {
cout << "NO\n";
return;
}
}
cout << (prev_keep || prev_flip ? "YES" : "NO") << "\n";
}

int main() {
ios_base::sync_with_stdio(false);
cin.tie(NULL);
int T;
cin >> T;
while (T--) {
solve();
}
}