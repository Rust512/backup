#include <bits/stdc++.h>

#define ll long long

using namespace std;

void initIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("./input.txt", "r", stdin);
    freopen("./output.txt", "w", stdout);
#endif
}

ll minSplitDifference(int *arr, int n, ll left, ll right)
{
    if (n == 0)
    {
        return abs(left - right);
    }

    return min(minSplitDifference(arr, n - 1, left + 1LL * arr[n - 1], right),
               minSplitDifference(arr, n - 1, left, right + 1LL * arr[n - 1]));
}

void solve()
{
    int n;
    cin >> n;
    int *weights = new int[n];

    for (int i = 0; i < n; i++) {
        cin >> weights[i];
    }

    cout << minSplitDifference(weights, n, 0LL, 0LL) << endl;
}

int main()
{
    initIO();
    // int t; cin >> t;
    // while (t--) {
    solve();
    // }
    return 0;
}