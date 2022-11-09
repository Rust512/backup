#include <string>
#include <iostream>

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
    string s; cin >> s;
    string left = s.substr(0, n/2), right = s.substr(n/2);
    cout << (left == right ? "YES\n" : "NO\n");
}

int main () {
    initIO();
    int t; cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}