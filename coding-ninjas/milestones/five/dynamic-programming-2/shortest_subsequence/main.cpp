#include <iostream>
#include <vector>

void initIO() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

#ifndef ONLINE_JUDGE
    freopen("./input.txt", "r", stdin);
    freopen("./output.txt", "w", stdout);
#endif
}

constexpr int INF = 1E9;

int solve(const std::string_view S, const std::string_view V) {
    auto n = (int)S.size();
    auto m = (int)V.size();
    int i;
    int j;
    int prev;
    std::vector<std::vector<int>> dp(n + 1, std::vector<int>(m + 1));
    std::vector<std::vector<int>> next(n + 1, std::vector<int>(m + 1));
    for (i = 0; i < n + 1; i++) {
        prev = -1;
        for (j = 0; j < m + 1; j++) {
            if (S[i] == V[j]) {
                prev = j;
            }
            next[i + 1][j + 1] = prev;
        }
    }
    for (i = 1; i <= n; i++)
        dp[i][0] = 1;
    for (i = 0; i <= m; i++)
        dp[0][i] = INF;
    for (i = 1; i < n + 1; i++) {
        for (j = 1; j < m + 1; j++) {
            if (next[i][j] == -1) {
                dp[i][j] = 1;
            } else {
                dp[i][j] = std::min(dp[i - 1][j], 1 + dp[i - 1][next[i][j]]);
            }
        }
    }
    return dp[n][m];
}

int main() {
    initIO();
    std::string s;
    std::string v;
    std::cin >> s >> v;
    std::cout << solve(s, v);
    return 0;
}
