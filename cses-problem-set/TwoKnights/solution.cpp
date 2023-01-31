#include <bits/stdc++.h>

#define ll long long

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
    vector<ll> arrange(n + 1);
    arrange[0] = 0LL;
    arrange[1] = 0LL;
    arrange[2] = 0LL;

    for (int i = 3; i <= n; i++) {
        arrange[i] = arrange[i - 1] + 1LL * (8 * i - 16);
    }

    for (int i = 1; i <= n; i++) {
        arrange[i] = (((1LL * i * i) * (1LL * i * i - 1LL)) / 2LL) - arrange[i];
        cout << arrange[i] << ' ';
    }

    cout << endl;
}


int main () {
    initIO();
    // int t; cin >> t;
    // while (t--) {
    solve();
    // }
    return 0;
}