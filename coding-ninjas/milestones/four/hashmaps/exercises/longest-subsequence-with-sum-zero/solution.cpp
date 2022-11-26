#include <iostream>
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

int lengthOfLongestSubsetWithZeroSum(int* arr, int n) {
    unordered_map<int, int> prefix;
    prefix.insert(make_pair(0, -1));
    int sum = 0, maxLength = 0;

    for (int i = 0; i < n; i++) {
        sum += arr[i];
        if (prefix.find(sum) == prefix.end()) {
            prefix.insert(make_pair(sum, i));
        } else {
            maxLength = max(i - prefix[sum], maxLength);
        }
    }

    return maxLength;
}

int main() {
    initIO();
    int size;
    cin >> size;

    int* arr = new int[size];

    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    cout << lengthOfLongestSubsetWithZeroSum(arr, size);

    delete[] arr;
}
