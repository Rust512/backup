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
	int n; cin >> n;
	if (n == 1) {
		printf("1\n");
		return;
	}

	if (n < 4) {
		printf("NO SOLUTION\n");
		return;
	}

	//print all the even numbers
	for (int i = 2; i <= n; i += 2) {
		printf("%d ", i);
	}

	//print all the odd numbers
	for (int i = 1; i <= n; i += 2) {
		printf("%d ", i);
	}

	printf("\n");
}
 
int main() {
    initIO();
    solve();
    return 0;
}