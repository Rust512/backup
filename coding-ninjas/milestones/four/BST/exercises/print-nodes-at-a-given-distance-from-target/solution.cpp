#include "../../BinaryTree.cpp"
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

void printNodesAtDepthK(BinaryTreeNode<int>* root, int k) {
    if (root == nullptr || k < 0) return;

    if (k == 0) cout << root->data << endl;

    printNodesAtDepthK(root->left, k - 1);
    printNodesAtDepthK(root->right, k - 1);
}

int helper(BinaryTreeNode<int>* node, int target, int k) {
    if (node == nullptr) return -1;

    if (node->data == target) {
        printNodesAtDepthK(node, k);
        return 0;
    }

    int leftDist = helper(node->left, target, k);
    if (leftDist != -1) {
        if (leftDist + 1 == k) {
            cout << node->data << endl;
            return -1;
        }
        printNodesAtDepthK(node->right, k - leftDist - 2);
        return leftDist + 1;
    }

    int rightDist = helper(node->right, target, k);
    if (rightDist != -1) {
        if (rightDist + 1 == k) {
            cout << node->data << endl;
            return -1;
        }
        printNodesAtDepthK(node->left, k - rightDist - 2);
        return rightDist + 1;
    }

    return -1;
}

void nodesAtDistanceK(BinaryTreeNode<int> *root, int node, int k) {
    int dist = helper(root, node, k);
}

int main() {
    initIO();
    BinaryTreeNode<int>* root = takeInput();
    int targetNode, k;
    cin >> targetNode >> k;
    nodesAtDistanceK(root, targetNode, k);
    delete root;
    return 0;
}
