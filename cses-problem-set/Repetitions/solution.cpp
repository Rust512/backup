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

size_t length(const char *str) {
	size_t length = 0;
	while (str[length++] != '\0') {}
	return length;
}
 
void solve() {
	char *str = new char[1000001];
	cin >> str;
	int n = (int) length(str);

	int count = 1, maxCount = 1;
	for (int i = 1; i < n; i++) {
		if (str[i] == str[i - 1]) {
			count++;
			continue;
		}
		maxCount = max(maxCount, count);
		count = 1;
	}

	maxCount = max(maxCount, count);
	cout << maxCount << '\n';
}
 
int main() {
    initIO();
    solve();
    return 0;
}