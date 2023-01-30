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
	int n, num; cin >> n;
	ll sum = 0LL;
	for (int i = 0; i < n - 1; i++) {
		cin >> num;
		sum += (1LL * num);
	}

	int missingNumber = (int)(((1LL * n * (n + 1)) / 2) - sum);

	cout << missingNumber << '\n';
}

int main() {
    initIO();
    solve();
    return 0;
}