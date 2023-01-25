#include <iostream>
#include <vector>

#define N 100001
#define MOD 1000000007

using namespace std;

vector<long long int> memo(N, 0);

void initIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
#ifndef ONLINE_JUDGE
    std::freopen("./input.txt", "r", stdin);
    std::freopen("./output.txt", "w", stdout);
#endif
}

void init() {
    memo[1] = 1;
    memo[2] = 2;
    memo[3] = 4;

    for (int i = 4; i < N; i++) {
        memo[i] = (memo[i - 1] + memo[i - 2] + memo[i - 3]) % MOD;
    }
}

int main() {
    initIO();
    init();
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        cout << memo[n] << endl;
    }
    return 0;
}