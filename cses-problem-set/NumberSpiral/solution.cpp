#include <bits/stdc++.h>
 
#define ll long long
 
using namespace std;
 
void initIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
 
#ifndef ONLINE_JUDGE
    freopen("./input.txt", "r", stdin);
    freopen("./output.txt", "w", stdout);
#endif
}
 
void solve() {
	int t; cin >> t;
	while (t--) {
		int x, y;
		cin >> x >> y;
		if (x == y) {
			cout << (1LL * x * x - 1LL * x + 1LL) << endl;
			continue;
		}
		int z = max(x, y);
		ll answer;
		if (x == z) {
			answer = (x % 2 == 0) ? (1LL * x * x - 1LL * y + 1LL) : 
				(1LL * (x - 1) * (x - 1) + 1LL * y);
		} else {
			answer = (y % 2 == 0) ? (1LL * (y - 1) * (y - 1) + 1LL * x) : 
				(1LL * y * y - 1LL * x + 1LL);
		}
		cout << answer << endl;
	}
}
 
int main() {
    initIO();
    solve();
    return 0;
}