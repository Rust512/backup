#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

void initIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

vector<int> kSmallest(int arr[], int n, int k) {
    priority_queue<int> pq;
    for (int i = 0; i < k; i++) {
        pq.push(arr[i]);
    }

    for (int i = k; i < n; i++) {
        int max = pq.top();
        if (arr[i] < max) {
            pq.pop();
            pq.push(arr[i]);
        }
    }

    vector<int> res(k);
    for (int& k: res) {
        k = pq.top();
        pq.pop();
    }

    return res;
}

int main() {
    initIO();
    int size;
    cin >> size;

    int *input = new int[size];

    for (int i = 0; i < size; i++) {
        cin >> input[i];
    }

    int k;
    cin >> k;

    vector<int> output = kSmallest(input, size, k);
    sort(output.begin(), output.end());

    for (int i = 0; i < output.size(); i++) {
        cout << output[i] << " ";
    }

    delete[] input;
}