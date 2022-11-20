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

void bottomTopHeapify(int arr[], int end) {
    int childIndex = end;
    
    while (childIndex > 0) {
        int parentIndex = (childIndex - 1) / 2;
        if (arr[childIndex] < arr[parentIndex]) {
            swap(arr[childIndex], arr[parentIndex]);
        } else {
            break;
        }
        childIndex = parentIndex;
    }
}

int getLeft(int i, int end) {
    int left = 2 * i + 1;
    return (left < end) ? left : -1;
}

int getRight(int i, int end) {
    int right = 2 * i + 2;
    return (right < end) ? right : -1;
}

void topBottomHeapify(int arr[], int end) {
    int parentIndex = 0;
    while (true) {
        int leftChild = getLeft(parentIndex, end);
        int rightChild = getRight(parentIndex, end);
        int maxIndex = parentIndex;

        if (leftChild != -1 && arr[leftChild] < arr[maxIndex]) {
            maxIndex = leftChild;
        }
        if (rightChild != -1 && arr[rightChild] < arr[maxIndex]) {
            maxIndex = rightChild;
        }

        if (parentIndex == maxIndex) {
            break;
        } else {
            swap(arr[parentIndex], arr[maxIndex]);
            parentIndex = maxIndex;
        }
    }
}

void heapSort(int arr[], int n) {
    if (n == 1) return;

    for (int i = 1; i < n; i++) {
        bottomTopHeapify(arr, i);
    }

    swap(arr[0], arr[n - 1]);
    for (int end = n - 1; end > 0; end--) {
        topBottomHeapify(arr, end);
        swap(arr[0], arr[end - 1]);
    }
}

int main() {
    initIO();
    int size;
    cin >> size;

    int *input = new int[size];

    for (int i = 0; i < size; i++) {
        cin >> input[i];
    } 

    heapSort(input, size);

    for (int i = 0; i < size; i++) {
        cout << input[i] << " ";
    } 

    delete[] input;
    return 0;
}