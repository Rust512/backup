#include "../../BinaryTree.cpp"
#include <vector>
#include <algorithm>

using namespace std;

void initIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

inline int compare(const int a, const int b) { return (a < b) ? -1 : (a > b); }

void flattenBinaryTree(BinaryTreeNode<int>* root, vector<int>* res) {
    if (root == nullptr) return;
    flattenBinaryTree(root->left, res);
    res->push_back(root->data);
    flattenBinaryTree(root->right, res);
}

void pairSum(BinaryTreeNode<int>* root, int target) {
    vector<int> *flat = new vector<int>();
    flattenBinaryTree(root, flat);

    sort(flat->begin(), flat->end());

    int start = 0, end = (int)flat->size() - 1;

    while (start < end) {
        int sum = flat->at(start) + flat->at(end);
        switch (compare(sum, target)) {
            case -1: {
                start++;
                break;
            }
            case 0: {
                cout << flat->at(start) << ' ' << flat->at(end) << '\n';
                start++;
                end--;
                break;
            }
            case 1: {
                end--;
                break;
            }
        }
    }

    delete flat;
}

int main() {
    initIO();
    BinaryTreeNode<int>* root = takeInput();
    int sum;
    cin >> sum;
    pairSum(root, sum);
    return 0;
}