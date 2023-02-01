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
    string s; cin >> s;
    int *freq = new int[26];
    for (int i = 0; i < 26; i++) {
        freq[i] = 0;
    }

    for (char letter: s) {
        freq[letter - 'A']++;
    }

    int odds = 0;
    for (int i = 0; i < 26; i++) {
        odds += (freq[i] % 2 == 1);
    }

    if (odds > 1) {
        cout << "NO SOLUTION\n";
        return;
    }

    string palindrome;
    char oddChar = ' ';
    for (int i = 0; i < 26; i++) {
        if (freq[i] % 2 == 1) {
            oddChar = (char) ('A' + i);
            continue;
        }

        palindrome += string(freq[i] / 2, (char)('A' + i));
    }

    string rev(palindrome);
    reverse(rev.begin(), rev.end());

    if (oddChar != ' ') {
        palindrome += string(freq[oddChar - 'A'], oddChar);
    }

    cout << palindrome + rev << endl;
}


int main () {
    initIO();
    // int t; cin >> t;
    // while (t--) {
    solve();
    // }
    return 0;
}