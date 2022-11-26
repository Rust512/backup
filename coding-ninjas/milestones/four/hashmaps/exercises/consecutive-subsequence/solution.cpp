#include <iostream>
#include <vector>
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

vector<int> longestConsecutiveIncreasingSequence(int *arr, int n) {
    unordered_map<int, bool> done;
    for (int i = 0; i < n; i++) {
        done.insert(make_pair(arr[i], false));
    }

    int maxLength = 0, maxStart = 0;
    for (int i = 0; i < n; i++) {
        if (done.count(arr[i] - 1) > 0 && !done[arr[i]]) {
            done[arr[i]] = true;
            continue;
        } else {
            int current = arr[i];
            while (done.count(current + 1) > 0) {current++;}
            if (current - arr[i] + 1 > maxLength) {
                maxLength = current - arr[i] + 1;
                maxStart = arr[i];
            }
        }
    }

    vector<int> result;
    result.push_back(maxStart);
    if (maxLength > 1) {
        result.push_back(maxStart + maxLength - 1);
    }

    return result;
}

int main() {
    initIO();
    int size;
    cin >> size;

    int* arr = new int[size];

    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    vector<int> ans = longestConsecutiveIncreasingSequence(arr, size);

    for (auto i = ans.begin(); i != ans.end(); ++i)
        cout << *i << " ";

    delete[] arr;
}
