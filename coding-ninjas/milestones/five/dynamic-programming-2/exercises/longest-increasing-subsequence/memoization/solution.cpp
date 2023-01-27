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

int longestSubsequenceEndingHere(int *arr, int *memo, int n) {
    if (n == 1) {
        return 1;
    }

    if (memo[n - 1] != -1) {
        return memo[n - 1];
    }

    int maxLength = 1;
    for (int i = n - 2; i >= 0; i--) {
        if (arr[i] < arr[n - 1]) {
            maxLength = max(maxLength, 1 + longestSubsequenceEndingHere(arr, memo, i + 1));
        }
    }

    memo[n - 1] = maxLength;

    return maxLength;
}

int longestIncreasingSubsequence(int* arr, int n) {
    int *memo = new int[n];
    for (int i = 0; i < n; i++) {
        memo[i] = -1;
    }
	int maxLength = 1;

    for (int i = 0; i < n; i++) {
        maxLength = max(maxLength, longestSubsequenceEndingHere(arr, memo, i + 1));
    }

    return maxLength;
}

int main() {
    initIO();
    int n;
    cin >> n;
    int* arr = new int[n];

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << longestIncreasingSubsequence(arr, n);
    return 0;
}
