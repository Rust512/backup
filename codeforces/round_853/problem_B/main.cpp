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
    string binary_string;
    getline(cin, binary_string);

    int start = 0;
    int end = size - 1;
    bool start_inverting = false;
    bool is_palindrome = true;

    while (start < end) {
        if (binary_string[start] == binary_string[end]) {
            start++;
            end--;
            start_inverting = false;
        } else if (binary_string[start] == '0') {
            is_palindrome = false;
            if (start_inverting) {
                continue;
            } else {
                start_inverting = true;
            }
        }
    }
}