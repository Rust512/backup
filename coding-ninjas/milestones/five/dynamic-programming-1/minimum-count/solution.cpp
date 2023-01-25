#include <iostream>
#include <vector>

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

int minCount(int n) {
    if (n == 0 || n == 1 || n == 2) {
        return n;
    }

    vector<int> memo(n + 1, 0);
    memo.at(0) = 0;
    memo.at(1) = 1;
    memo.at(2) = 2;

    for (int i = 3; i <= n; i++) {
        int minimumCount = i;
        for (int j = 1; j * j <= i; j++) {
            minimumCount = min(minimumCount, 1 + memo.at(i - j * j));
        }
        memo.at(i) = minimumCount;
    }

    return memo.at(n);
}

int main() {
    initIO();
    int n;
    cin >> n;

    cout << minCount(n);

    return 0;
}