#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

void initIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

string uniqueChar(string str) {
	string output;
    unordered_map<char, int> unique;
    for (char c: str) {
        if (unique.count(c) > 0) { continue; }
        output.push_back(c);
        unique.insert(make_pair(c, 1));
    }
    return output;
}

int main() {
    initIO();
    string str;
    cin >> str;
    cout << uniqueChar(str);
}
