#include <iostream>
#include <vector>
#include <algorithm>

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

    for (int &x: a) {
        cin >> x;
    }

    cout << *max_element(a.begin(), a.end()) << endl;
}

int main() {
    initIO();
    int t; cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
