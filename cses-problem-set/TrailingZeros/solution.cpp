#include <bits/stdc++.h>

using namespace std;

void initIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("./input.txt", "r", stdin);
    freopen("./output.txt", "w", stdout);
#endif
}

void solve() {
    int n; cin >> n;
    int trailingZeros = 0;
    
    while (n != 0) {
        n /= 5;
        trailingZeros += n;
    }

    cout << trailingZeros << '\n';
}

int main () {
    initIO();
    // int t; cin >> t;
    // while (t--) {
    solve();
    // }
    return 0;
}