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

int getPairsWithDifferenceK(int *arr, int n, int k) {
	unordered_map<int, int> freq;
    for (int i = 0; i < n; i++) {
        freq[arr[i]]++;
    }

    int count = 0;
    for (auto &entry: freq) {
        if (k == 0) {
            count += (entry.second * (entry.second - 1)) / 2;
            continue;
        }
        int smaller = entry.first - k;
        int larger = entry.first + k;

        if (freq.find(smaller) != freq.end()) {
            count += entry.second * freq[smaller];
        }

        if (freq.find(larger) != freq.end()) {
            count += entry.second * freq[larger];
        }

        entry.second = 0;
    }

    return count;
}

int main() {
    initIO();
    int n;
    cin >> n;

    int *input = new int[n];

    for (int i = 0; i < n; i++) {
        cin >> input[i];
    }

    int k;
    cin >> k;

    cout << getPairsWithDifferenceK(input, n, k);

    delete[] input;
}
