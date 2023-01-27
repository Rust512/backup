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

int maxMoneyLooted(int *arr, int n) {
    int *memo = new int[n];

    for (int i = 0; i < n; i++) {
        memo[i] = 0;
    }

    memo[0] = arr[0];
    memo[1] = max(arr[1], arr[0]);

    for (int i = 2; i < n; i++) {
        memo[i] = max(arr[i] + memo[i - 2], memo[i - 1]);
    }

    return memo[n - 1];
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
