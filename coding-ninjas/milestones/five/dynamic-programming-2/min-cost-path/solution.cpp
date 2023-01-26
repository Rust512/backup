#include <bits/stdc++.h>

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

bool isValid(int m, int n, int row, int col) {
    return (row >= 0) && (row < m) && (col >= 0) && (col < n);
}

int recursiveMinCostPath(int **input, int m, int n, int row, int col) {
    if (row == m - 1 && col == n - 1) {
        return input[row][col];
    }

    if (!isValid(m, n, row, col)) {
        return INT_MAX;
    }

    int right = recursiveMinCostPath(input, m, n, row, col + 1);
    int diagonal = recursiveMinCostPath(input, m, n, row + 1, col + 1);
    int down = recursiveMinCostPath(input, m, n, row + 1, col);

    return input[row][col] + min({right, diagonal, down});
}

int minCostPath(int **input, int m, int n) {
    return recursiveMinCostPath(input, m, n, 0, 0);
}

int main() {
    initIO();
    int **arr, n, m;
    cin >> n >> m;
    arr = new int *[n];
    for (int i = 0; i < n; i++) {
        arr[i] = new int[m];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }
    cout << minCostPath(arr, n, m) << endl;
}