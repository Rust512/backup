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

bool isMaxHeap(int arr[], int n) {
    if (n == 1) { return true; }
    int end = (n - 1) / 2;

    for (int i = 0; i <= end; i++) {
        int left = 2 * i + 1;
        int right = left + 1;

        if (left < n && arr[left] > arr[i]) {
            return false;
        }

        if (right < n && arr[right] > arr[i]) {
            return false;
        }
    }

    return true;
}

int main() {
    initIO();
    int n;
    cin >> n;
    int *arr = new int[n];

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << (isMaxHeap(arr, n) ? "true\n" : "false\n");

    delete[] arr;
}