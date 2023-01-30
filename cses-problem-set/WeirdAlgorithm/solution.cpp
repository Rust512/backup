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

int main() {
    initIO();
    int n; cin >> n;

    while (n != 1) {
        cout << n << ' ';
        if (n % 2 == 0) {
            n /= 2;
        } else {
            n *= 3;
            n++;
        }
    }
    cout << 1 << endl;

    return 0;
}
