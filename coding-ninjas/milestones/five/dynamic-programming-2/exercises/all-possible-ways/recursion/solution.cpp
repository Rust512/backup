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

int recursiveFunction(int target, int power, int base) {
    int result = pow(base, power);

    if (result > target) {
        return 0;
    }

    if (result == target) {
         return 1;
    }

    return recursiveFunction(target - result, power, base + 1) +
            recursiveFunction(target, power, base + 1);
}

int getAllWays(int a, int b) {
    return recursiveFunction(a, b, 1);
}

int main() {
    initIO();
    int a, b;
    cin >> a >> b;
    cout << getAllWays(a, b);
    
//    cout << pow(a, b);
    return 0;
}
