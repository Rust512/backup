#include <iostream>
#include <queue>
#include <vector>

using namespace std;

void initIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

vector<int> kLargest(int input[], int n, int k) {
    priority_queue<int, vector<int>, greater<int>> pq;

    for (int i = 0; i < k; i++) {
        pq.push(input[i]);
    }

    for (int i = k; i < n; i++) {
        int min = pq.top();
        if (input[i] > min) {
            pq.pop();
            pq.push(input[i]);
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
	
	int size;
	cin >> size;
	int *input = new int[1 + size];
	
	for(int i = 0; i < size; i++)
		cin >> input[i];
    
    int k;
    cin >> k;
    
    vector<int> output = kLargest(input, size, k);
    for(int i = 0; i < output.size(); i++)
        cout << output[i] << endl;
	
	return 0;
}
