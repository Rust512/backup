#include <bits/stdc++.h>

#define MOD 1000000007

using namespace std;


void initIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("./input.txt", "r", stdin);
    freopen("./output.txt", "w", stdout);
#endif
}

int countBitStrings(int n) {
    int res = 1, two = 2;

    while (n != 0) {
        if (n & 1) {
            res = (1LL * res * two) % MOD;
        }
        two = (1LL * two * two) % MOD;
        n >>= 1;
    }

    return res;
}

void solve() {
    int n; cin >> n;
    cout << countBitStrings(n) << '\n';
}


int main () {
    initIO();
    // int t; cin >> t;
    // while (t--) {
    solve();
    // }
    return 0;
}