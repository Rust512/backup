#include <iostream>

using namespace std;

void initIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
#ifndef ONLINE_JUDGE
    std::freopen("./input.txt", "r", stdin);
    std::freopen("./output.txt", "w", stdout);
#endif
}

int maxMoneyLooted(int *arr, int n, int *memo) {
    if (n == 0) {
        return 0;
    } else if (n == 1) {
        return arr[0];
    }

    if (memo[n] != -1) {
        return memo[n];
    }

    memo[n] = max(maxMoneyLooted(arr + 1, n - 1, memo), arr[0] + maxMoneyLooted(arr + 2, n - 2, memo));
    return memo[n];
}

int maxMoneyLooted(int *arr, int n) {
    int *memo = new int[n + 1];
    for (int i = 0; i <= n; i++) {
        memo[i] = -1;
    }

    return maxMoneyLooted(arr, n, memo);
}

int main() {
    initIO();
    int n;
	cin >> n;
	int *arr = new int[n];
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	cout << maxMoneyLooted(arr, n);

	delete[] arr;
    return 0;
}
