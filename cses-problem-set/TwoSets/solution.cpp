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

void printVector(const vector<int>& arr) {
    cout << arr.size() << '\n';
    for (const int& x: arr) {
        cout << x << ' ';
    }
    cout << '\n';
}


void solve() {
    int n; cin >> n;
    if (n % 4 != 0 && (n + 1) % 4 != 0) {
        cout << "NO\n";
        return;
    }

    cout << "YES\n";
    vector<int> first, second;
    if ((n + 1) % 4 == 0) {
        second.push_back(n--);
    }

    for (int i = 1; i <= n / 2; i += 2) {
        first.push_back(i);
        first.push_back(n - i + 1);
    }

    for (int i = 2; i <= n / 2; i += 2) {
        second.push_back(i);
        second.push_back(n - i + 1);
    }

    printVector(first);
    printVector(second);
}


int main () {
    initIO();
    // int t; cin >> t;
    // while (t--) {
    solve();
    // }
    return 0;
}