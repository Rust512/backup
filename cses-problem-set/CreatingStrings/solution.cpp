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

int factorial(int n) {
    if (n == 0 || n == 1) {
        return 1;
    }

    int res = 1;
    for (int i = 2; i <= n; i++) {
        res *= i;
    }

    return res;
}


void solve() {
    string s; cin >> s;
    int *freq = new int[26];
    for (int i = 0; i < 26; i++) {
        freq[i] = 0;
    }

    for (const char c: s) {
        freq[c - 'a']++;
    }

    int totalPermutations = factorial((int) s.length());

    for (int i = 0; i < 26; i++) {
        totalPermutations /= factorial(freq[i]);
    }

    cout << totalPermutations << endl;

    sort(s.begin(), s.end());
    do {
        cout << s << endl;
    } while (next_permutation(s.begin(), s.end()));
}


int main () {
    initIO();
    // int t; cin >> t;
    // while (t--) {
    solve();
    // }
    return 0;
}