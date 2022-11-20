#include <iostream>
#include <vector>
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

class comparePair {
public:
    bool operator() (pair<int, int> const& a, pair<int, int> const& b) {
        return (a.first > b.first);
    }
};

vector<int> mergeKSortedArrays(vector<vector<int>*> input) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, comparePair> pq;
    int k = input.size();
    vector<int> indices(k, 0);

    for (int i = 0; i < k; i++) {
        pq.push(make_pair(input[i]->at(0), i));
    }

    vector<int> output;

    while (!pq.empty()) {
        pair<int, int> smallest = pq.top();
        pq.pop();
        output.push_back(smallest.first);
        int origin = smallest.second;
        if (++indices[origin] < input[origin]->size()) {
            pq.push(make_pair(input[origin]->at(indices[origin]), origin));
        }
    }

    return output;
}

int main() {
    initIO();
    int k;
    cin >> k;

    vector<vector<int> *> input;

    for (int j = 1; j <= k; j++) {
        int size;
        cin >> size;
        vector<int> *current = new vector<int>;

        for (int i = 0; i < size; i++) {
            int a;
            cin >> a;
            current->push_back(a);
        }

        input.push_back(current);
    }

    vector<int> output = mergeKSortedArrays(input);

    for (int i = 0; i < output.size(); i++) {
        cout << output[i] << " ";
    }

    return 0;
}
