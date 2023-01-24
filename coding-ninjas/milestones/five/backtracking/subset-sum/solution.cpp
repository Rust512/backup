#include <bits/stdc++.h>
using namespace std;

void findSubsetSum(int *arr, int i, int sum, int n, int k, int &cnt) {
  if (i == n) {
    if (sum == k) {
      cnt++;
    }
    return;
  }

  findSubsetSum(arr, i + 1, sum + arr[i], n, k, cnt);
  findSubsetSum(arr, i + 1, sum, n, k, cnt);
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;

    int *arr = new int[n];

    for (int i = 0; i < n; i++) {
      cin >> arr[i];
    }

    int count = 0;
    findSubsetSum(arr, 0, 0, n, k, count);
    cout << count << endl;
  }
  return 0;
}
