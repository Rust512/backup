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
    int x, y; cin >> x >> y;
    if ((x + y) % 3 != 0) {
        cout << "NO\n";
        return;
    }

    int z = (x + y) / 3;
    if (x >= z && y >= z) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}


int main () {
    initIO();
    int t; cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}