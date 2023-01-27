#include <iostream>

using namespace std;

void initIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
#ifndef ONLINE_JUDGE
    std::freopen("./input.txt", "r", stdin);
    std::freopen("./output.txt", "w", stdout);
#endif
}

int knapsack(int *weights, int *values, int n, int maxWeight) {
    if (n == 0) {
        return 0;
    }

    if (weights[0] > maxWeight) {
        return knapsack(weights + 1, values + 1, n - 1, maxWeight);
    }

    return max(values[0] + knapsack(weights + 1, values + 1, n - 1, maxWeight - weights[0]),
               knapsack(weights + 1, values + 1, n - 1, maxWeight));
}

int main() {
    initIO();
    int n;
    cin >> n;

    int *weights = new int[n];
    int *values = new int[n];

    for (int i = 0; i < n; i++) {
        cin >> weights[i];
    }

    for (int i = 0; i < n; i++) {
        cin >> values[i];
    }

    int maxWeight;
    cin >> maxWeight;

    cout << knapsack(weights, values, n, maxWeight) << endl;

    delete[] weights;
    delete[] values;
}
