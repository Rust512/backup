#include <queue>
#include <iostream>

using namespace std;

void initIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

void findMedian(int *arr, int n) {
    priority_queue<int> left;
    priority_queue<int, vector<int>, greater<int>> right;

    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            if (!right.empty() && (arr[i] >= right.top())) {
                left.push(right.top());
                right.pop();
                right.push(arr[i]);
            } else {
                left.push(arr[i]);
            }
            cout << left.top() << ' ';
        } else {
            if (arr[i] <= left.top()) {
                right.push(left.top());
                left.pop();
                left.push(arr[i]);
            } else {
                right.push(arr[i]);
            }
            cout << (left.top() + right.top())/2 << ' ';
        }
    }
}

int main() {
    initIO();
    int n;
    cin >> n;

    int* arr = new int[n];

    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    findMedian(arr,n);

    delete[] arr;
}
