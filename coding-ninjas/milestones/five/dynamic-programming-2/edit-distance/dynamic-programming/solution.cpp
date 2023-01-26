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

int editDistance(string s1, string s2) {
    int m = (int) s1.length();
    int n = (int) s2.length();

    int **memo = new int *[m + 1];
    for (int i = 0; i <= m; i++) {
        memo[i] = new int[n + 1];
    }

    //fill first row
    for (int j = 0; j <= n; j++) {
        memo[0][j] = j;
    }

    //fill first column
    for (int i = 1; i <= m; i++) {
        memo[i][0] = i;
    }

    //fill rest cells
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (s1.at(m - i) == s2.at(n - j)) {
                memo[i][j] = memo[i - 1][j - 1];
            } else {
                memo[i][j] = 1 + min({memo[i - 1][j], memo[i][j - 1], memo[i - 1][j - 1]});
            }
        }
    }

    return memo[m][n];
}

int main() {
    initIO();
    string s1;
    string s2;

    cin >> s1;
    cin >> s2;

    cout << editDistance(s1, s2);
}
