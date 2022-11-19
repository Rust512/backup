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
    std::vector<int> pq;

   public:
    PriorityQueue() {}

    void insert(int element) {
        pq.push_back(element);
        int childIndex = pq.size() - 1;

        while (childIndex > 0) {
          int parentIndex = (childIndex - 1) / 2;

          if (pq[childIndex] > pq[parentIndex]) {
            std::swap(pq[parentIndex], pq[childIndex]);
          } else {
            break;
          }

          childIndex = parentIndex;
        }
    }

    int getMax() {
        if (isEmpty()) return INT_MIN;
        return pq[0];
    }

    int getLeftChild(int index) {
      int leftChildIndex = 2 * index + 1;
      return (leftChildIndex < getSize()) ? leftChildIndex : -1;
    }

    int getRightChild(int index) {
      int rightChildIndex = 2 * index + 2;
      return (rightChildIndex < getSize()) ? rightChildIndex : -1;
    }

    int removeMax() {
      if (isEmpty()) {
        return INT_MIN;
      }
      int maxElement = pq[0], n = getSize();
      std::swap(pq[0], pq[n - 1]);
      pq.pop_back();
      n--;
      int index = 0;
      while (true) {
        int leftChild = getLeftChild(index);
        int rightChild = getRightChild(index);
        int maxIndex = index;
        if (leftChild != -1 && pq[leftChild] > pq[maxIndex]) {
          maxIndex = leftChild;
        }

        if (rightChild != -1 && pq[rightChild] > pq[maxIndex]) {
          maxIndex = rightChild;
        }

        if (maxIndex == index) {
          break;
        } else {
          std::swap(pq[maxIndex], pq[index]);
          index = maxIndex;
        }
      }
      return maxElement;
    }

    int getSize() { 
        return pq.size();
    }

    bool isEmpty() {
        return pq.size() == 0;
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
            case 2:  // getMax
                cout << pq.getMax() << "\n";
                break;
            case 3:  // removeMax
                cout << pq.removeMax() << "\n";
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