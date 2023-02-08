#include <iostream>
#include <cmath>

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

int pow(int x, int y) {
    int res = 1;
    for (int k = y; k != 0; k /= 2) {
        if (k % 2 == 1) {
            res *= x;
        }
        x *= x;
    }
    return res;
}

int memoizationFunction(int target, int power, int base, int *memo) {
    int result = pow(base, power);

    if (result > target) {
        return 0;
    }

    if (result == target || target == 0) {
         return 1;
    }

    if (memo[target] != -1) {
        return memo[target];
    }

    memo[target] = memoizationFunction(target - result, power, base + 1, memo) +
           memoizationFunction(target, power, base + 1, memo);

    return memo[target];
}

int getAllWays(int a, int b) {
    int *memo = new int[a + 1];
    for (int i = 0; i <= a; i++) {
        memo[i] = -1;
    }

    int answer = memoizationFunction(a, b, 1, memo);

    for (int i = 0; i <= a; i++) {
        cout << i << '\t';
    }
    cout << endl;

    for (int i = 0; i <= a; i++) {
        cout << memo[i] << '\t';
    }

    cout << endl;
    return answer;
}

int main() {
    initIO();
    int a, b;
    cin >> a >> b;
    cout << getAllWays(a, b);
    return 0;
}
