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

int pairSum(int *arr, int n) {
	unordered_map<int, int> um;

    for (int i = 0; i < n; i++) {
        um[arr[i]]++;
    }

    int count = 0;
    for (pair<int, int> k: um) {
        if (k.first < 0) {
            continue;
        }
        else if (k.first == 0) {
            count += (k.second * (k.second - 1)) / 2;
        } else {
            int complement = -k.first;
            if (um.count(complement) > 0) {
                count += k.second * um.at(complement);
            }
        }
    }

    return count;
}

int main() {
    initIO();
    int n;
    cin >> n;

    int* arr = new int[n];

    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    cout << pairSum(arr, n);

    delete[] arr;
}
