#include <iostream>
#include <algorithm>

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

void printArray(int *arr, int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << ' ';
    }

    cout << endl;
}

int longestIncreasingSubsequence(const int* arr, int n) {
    int *memo = new int[n];
    memo[0] = 1;

    for (int i = 1; i < n; i++) {
        memo[i] = 1;
        for (int j = i - 1; j >= 0; j--) {
            if (arr[j] < arr[i]) {
                memo[i] = max(memo[i], 1 + memo[j]);
            }
        }
    }

    return *max_element(memo, memo + n);
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
