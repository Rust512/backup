#include <iostream>
#include <vector>

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

void solve(int testCase) {
    int n;
    cin >> n;
    vector<int> arr;
    vector<int> odd;
    vector<int> even;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (x % 2 == 1) {
            odd.push_back(i + 1);
        } else {
            even.push_back(i + 1);
        }
        arr.push_back(x);
    }

    int oddNumbers = (int) odd.size();
    int evenNumbers = (int) even.size();
    if (oddNumbers == 0) {
        cout << "NO\n";
    } else if (oddNumbers == 1) {
        cout << "YES\n"
             << odd.at(0) << ' '
             << even.at(0) << ' '
             << even.at(1) << endl;
    } else if (oddNumbers == 2) {
        if (evenNumbers == 1) {
            cout << "NO\n";
        } else {
            cout << "YES\n"
                 << odd.at(0) << ' '
                 << even.at(0) << ' '
                 << even.at(1) << endl;
        }
    } else {
        cout << "YES\n"
             << odd.at(0) << ' '
             << odd.at(1) << ' '
             << odd.at(2) << endl;
    }
}

int main() {
    initIO();
    int cases;
    cin >> cases;

    for (int i = 1; i <= cases; i++) {
        solve(i);
    }

    return 0;
}
