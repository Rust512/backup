#include <iostream>
#include <algorithm>

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

int findMaxSquareWithAllZeros(int **arr, int n, int m) {
    if (n == 0 || m == 0) {
        return 0;
    }
    auto table = new int* [n];

    for (int i = 0; i < n; i++) {
        table[i] = new int[m];
    }

    for (int i = 0; i < n; i++) {
        if (arr[i][0] == 0) {
            table[i][0] = 1;
        } else {
            table[i][0] = 0;
        }
    }

    for (int i = 0; i < m; i++) {
        if (arr[0][i] == 0) {
            table[0][i] = 1;
        } else {
            table[0][i] = 0;
        }
    }

    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            if (arr[i][j] == 1) {
                table[i][j] = 0;
                continue;
            }
            table[i][j] = 1 + min({table[i - 1][j - 1], table[i - 1][j], table[i][j - 1]});
        }
    }

    int max_square_size = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            max_square_size = max(max_square_size, table[i][j]);
        }
    }

    for (int i = 0; i < n; i++) {
        delete[] table[i];
    }

    delete[] table;

    return max_square_size;
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

    cout << findMaxSquareWithAllZeros(arr, n, m) << endl;

    delete[] arr;

    return 0;
}
