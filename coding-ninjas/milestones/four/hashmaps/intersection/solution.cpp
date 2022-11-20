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

void printIntersection(int arr1[], int arr2[], int n, int m) {
    unordered_map<int, int> um;
    for (int i = 0; i < n; i++) {
        um[arr1[i]]++;
    }

    for (int i = 0; i < m; i++) {
        if (um.count(arr2[i]) > 0 && um[arr2[i]] > 0) {
            cout << arr2[i] << endl;
            um[arr2[i]]--;
        }
    }
}

int main() {
    initIO();
    int n;
    cin >> n;

    int* arr1 = new int[n];

    for (int i = 0; i < n; ++i) {
        cin >> arr1[i];
    }

    int m;
    cin >> m;

    int* arr2 = new int[m];

    for (int i = 0; i < m; ++i) {
        cin >> arr2[i];
    }

    printIntersection(arr1, arr2, n, m);

    delete[] arr1;
    delete[] arr2;
}
