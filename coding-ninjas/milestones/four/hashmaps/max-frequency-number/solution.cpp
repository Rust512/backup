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

int highestFrequency(int arr[], int n) {
    unordered_map<int, int> um;
    for (int i = 0; i < n; i++) {
        um[arr[i]]++;
    }

    int maxFrequency = 0;
    for (pair<int, int> k: um) {
        maxFrequency = max(maxFrequency, k.second);
    }

    for (int i = 0; i < n; i++) {
        if (um[arr[i]] == maxFrequency) {
            return arr[i];
        }
    }
    
    return 0;
}

int main() {
    initIO();
    int n;
    cin >> n;

    int* arr = new int[n];

    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    cout << highestFrequency(arr, n);

    delete[] arr;
}
