#include <iostream>
#include <climits>

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

int knapsack(int *weights, int *values, int n, int maxWeight, int *memo) {
    if (n == 0 || maxWeight == 0) {
        return 0;
    }

    if (memo[maxWeight] != -1) {.
        return memo[maxWeight];
    }

    int answer;
    if (weights[0] > maxWeight) {
        answer = knapsack(weights + 1, values + 1, n - 1, maxWeight, memo);
    } else {
        answer = max(values[0] + knapsack(weights + 1, values + 1, n - 1, maxWeight - weights[0], memo),
               knapsack(weights + 1, values + 1, n - 1, maxWeight, memo));
    }

    memo[maxWeight] = answer;

    return answer;
}

int knapsack(int *weights, int *values, int n, int maxWeight) {
    int *memo = new int[maxWeight + 1];

    for (int i = 0; i <= maxWeight; i++) {
        memo[i] = -1;
    }

    knapsack(weights, values, n, maxWeight, memo);

    int max_value = INT_MIN;
    for (int i = 0; i <= maxWeight; i++) {
        max_value = max(max_value, memo[i]);
    }

    return max_value;
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
