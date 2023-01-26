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

int editDistance(string s1, string s2, int **memo) {
    if (s1.empty() || s2.empty()) {
        return (int) max(s1.size(), s2.size());
    }

    int m = (int) s1.length();
    int n = (int) s2.length();
    if (memo[m][n] != -1) {
        return memo[m][n];
    }

    int answer = 0;
    if (s1.at(0) == s2.at(0)) {
        answer = editDistance(s1.substr(1), s2.substr(1), memo);
    } else {
        int first = editDistance(s1.substr(1), s2, memo);
        int second = editDistance(s1, s2.substr(1), memo);
        int both = editDistance(s1.substr(1), s2.substr(1), memo);

        int deleteDistance = 1 + min(first, second);
        int replaceDistance = 1 + both;

        answer = min(deleteDistance, replaceDistance);
    }

    memo[m][n] = answer;

    return answer;
}

int editDistance(string s1, string s2) {
    int m = (int) s1.length();
    int n = (int) s2.length();

    int **memo = new int *[m + 1];
    for (int i = 0; i <= m; i++) {
        memo[i] = new int[n + 1];
        for (int j = 0; j <= n; j++) {
            memo[i][j] = -1;
        }
    }

    editDistance(s1, s2, memo);

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
