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
    vector<string> code;
    code.push_back("0");
    code.push_back("1");

    if (n == 1) {
        cout << "0\n1\n";
        return;
    }

    for (int i = 2; i <= n; i++) {
        int codes = code.size();
        for (int j = codes - 1; j >= 0; j--) {
            code.push_back('1' + code[j]);
        }
        for (int j = 0; j < codes; j++) {
            code[j] = '0' + code[j];
        }
    }

    for (const string& gray: code) {
        cout << gray << '\n';
    }
}


int main () {
    initIO();
    // int t; cin >> t;
    // while (t--) {
    solve();
    // }
    return 0;
}