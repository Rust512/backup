#include <iostream>

using namespace std;

void initIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
#ifndef ONLINE_JUDGE
    std::freopen("./input.txt", "r", stdin);
    std::freopen("./output.txt", "w", stdout);
#endif
}

int editDistance(string s1, string s2) {
    if (s1.empty() || s2.empty()) {
        return (int) max(s1.size(), s2.size());
    }

    if (s1.at(0) == s2.at(0)) {
        return editDistance(s1.substr(1), s2.substr(1));
    } else {
        int first = editDistance(s1.substr(1), s2);
        int second = editDistance(s1, s2.substr(1));
        int both = editDistance(s1.substr(1), s2.substr(1));

        int deleteDistance = 1 + min(first, second);
        int replaceDistance = 1 + both;

        return min(deleteDistance, replaceDistance);
    }
}

int main() {
    initIO();
    string s1;
    string s2;

    cin >> s1;
    cin >> s2;

    cout << editDistance(s1, s2);
}
