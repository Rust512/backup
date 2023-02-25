#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void initIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

#ifndef ONLINE_JUDGE
    freopen("./input.txt", "r", stdin);
    freopen("./output.txt", "w", stdout);
#endif
}

int main() {
    initIO();
    int n; cin >> n;
    vector<int> arr(n);

    for (int& x: arr) {
        cin >> x;
    }

    sort(arr.begin(), arr.end());

    int count_distinct = 1;
    for (int i = 1; i < n; i++) {
        if (arr[i - 1] != arr[i]) {
            count_distinct++;
        }
    }

    cout << count_distinct << '\n';

    return 0;
}
