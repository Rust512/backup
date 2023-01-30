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
	int n, x; cin >> n;
	ll moves = 0;
	cin >> x;
	int maxNum = x;
	for (int i = 0; i < n - 1; i++) {
		cin >> x;
		maxNum = max(maxNum, x);
		moves += 1LL * (maxNum - x);
	}

	cout << moves << '\n';
}
 
int main() {
    initIO();
    solve();
    return 0;
}