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

int buyTicket(int *arr, int n, int k) {
    queue<int> q;
    priority_queue<int> pq;

    for (int i = 0; i < n; i++) {
        q.push(i);
        pq.push(arr[i]);
    }

    int time = 0;

    while (!pq.empty()) {
        if (pq.top() == arr[q.front()]) {
            time++;
            pq.pop();
            if (q.front() == k) {
                break;
            }
            q.pop();
        } else {
            q.push(q.front());
            q.pop();
        }
    }

    return time;
}

int main() {
    initIO();
    int n;
    cin >> n;

    int *arr = new int[n];

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int k;
    cin >> k;

    cout << buyTicket(arr, n, k);

    delete[] arr;
}
