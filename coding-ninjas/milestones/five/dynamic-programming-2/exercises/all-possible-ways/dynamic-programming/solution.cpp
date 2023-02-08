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

int root(int a, int n) {
    int start = 1, end = n / 2, mid, result, raised;

    while (start <= end) {
        mid = start + (end - start) / 2;
        raised = pow(mid, n);
        if (raised == a) {
            return mid;
        } else if (raised < a) {
            start = mid + 1;
            result = mid;
        } else {
            end = mid - 1;
        }
    }

    return result;
}

int getAllWays(int a, int b) {
	int *memo = new int[a + 1];

    memo[0] = 0;
    memo[1] = 1;

    for (int i = 2; i <= a; i++) {
        memo[i] = 0;
        for (int j = 1; j <= root(i, b); j++) {
            memo[i] += memo[i - pow(j, b)];
        }
    }

    return memo[a];
}

int main() {
    initIO();
    int a, b;
    cin >> a >> b;
    cout << getAllWays(a, b);
    return 0;
}
