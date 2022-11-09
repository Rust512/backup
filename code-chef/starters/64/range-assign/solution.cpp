#include <iostream>
#include <vector>

using namespace std;

void initIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

void solve() {
    int n; cin >> n;
    vector<int> a(n);

    for (int &x: a) { cin >> x; }

    bool possible = false;
    for (int i = 1; i < n; i++) {
        if ((a[i - 1] == a[0]) && (a[i] == a[n - 1])) {
            possible = true;
        }
    }

    cout << ((possible || a[0] == a[n - 1]) ? "YES\n": "NO\n");
}

int main() {
    initIO();
    int t; cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}