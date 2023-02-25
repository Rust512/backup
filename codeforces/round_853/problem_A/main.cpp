#include <iostream>
#include <vector>
#include <algorithm>

void solve_test_case();

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
    int test_cases;
    cin >> test_cases;

    for (int i = 1; i <= test_cases; i++) {
        solve_test_case();
    }

    return 0;
}

void solve_test_case() {
    int size; cin >> size;
    vector<int> arr(size);

    for (int &entry: arr) { cin >> entry; }

    bool possible = false;
    for (int i = 1; i < size; i++) {
        for (int j = 0; j < i; j++) {
            if (__gcd(arr[i], arr[j]) < 3) {
                possible = true;
            }
        }
    }

    if (possible) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
    }
}
