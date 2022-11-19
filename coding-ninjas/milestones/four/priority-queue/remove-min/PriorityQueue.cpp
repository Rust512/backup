#include <vector>
#include <iostream>
#include <climits>

using namespace std;

void initIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

class PriorityQueue {
    vector<int> pq;

   public:
    bool isEmpty() { 
        return pq.size() == 0; 
    }

    int getSize() { 
        return pq.size(); 
    }

    int getMin() {
        if (isEmpty()) {
            return 0;
        }

        return pq[0];
    }

    void insert(int element) {
        pq.push_back(element);

        int childIndex = pq.size() - 1;

        while (childIndex > 0) {
            int parentIndex = (childIndex - 1) / 2;

            if (pq[childIndex] < pq[parentIndex]) {
                int temp = pq[childIndex];
                pq[childIndex] = pq[parentIndex];
                pq[parentIndex] = temp;
            } else {
                break;
            }

            childIndex = parentIndex;
        }
    }

    int getParent(int index) {
        return (index - 1)/2;
    }

    int getLeftChild(int index) {
        int leftChildIndex = 2 * index + 1;
        return (leftChildIndex < getSize()) ? leftChildIndex : -1;
    }

    int getRightChild(int index) {
        int rightChildIndex = 2 * index + 2;
        return (rightChildIndex < getSize()) ? rightChildIndex : -1;
    }

    int removeMin() {
        if (isEmpty()) { return INT_MIN; }
        int minElement = pq[0], n = getSize();
        swap(pq[0], pq[n - 1]);
        pq.pop_back();
        n--;
        int index = 0;
        while (true) {
            int leftChild = getLeftChild(index);
            int rightChild = getRightChild(index);
            int minIndex = index;
            if (leftChild != -1 && pq[leftChild] < pq[minIndex]) {
                minIndex = leftChild;
            }

            if (rightChild != -1 && pq[rightChild] < pq[minIndex]) {
                minIndex = rightChild;
            }

            if (minIndex == index) {
                break;
            } else {
                swap(pq[minIndex], pq[index]);
                index = minIndex;
            }
        }
        return minElement;
    }
};

int main() {
    initIO();
    PriorityQueue pq;

    int choice;
    cin >> choice;

    while (choice != -1) {
        switch (choice) {
            case 1:  // insert
                int element;
                cin >> element;
                pq.insert(element);
                break;
            case 2:  // getMin
                cout << pq.getMin() << "\n";
                break;
            case 3:  // removeMax
                cout << pq.removeMin() << "\n";
                break;
            case 4:  // size
                cout << pq.getSize() << "\n";
                break;
            case 5:  // isEmpty
                cout << (pq.isEmpty() ? "true\n" : "false\n");
            default:
                return 0;
        }
        
        cin >> choice;
    }
}