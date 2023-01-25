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

int balancedBTs(int n) {
    if (n < 2) {
        return 1;
    }

    int BIG_PRIME = 1000000007;
    long long int memo_zero = 1L, memo_one = 1L, memo_two;

    for (int i = 2; i <= n; i++) {
        memo_two = (memo_one * ((2 * memo_zero) % BIG_PRIME + memo_one) % BIG_PRIME) % BIG_PRIME;
        memo_zero = memo_one;
        memo_one = memo_two;
    }

    return (int)memo_two;
}

int main() {
    initIO();
    int n;
    cin >> n;
    cout << balancedBTs(n);
}