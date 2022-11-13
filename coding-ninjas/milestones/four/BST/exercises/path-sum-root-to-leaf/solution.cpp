#include "../../BinaryTree.cpp"
#include <iostream>
#include <string>

using namespace std;

void initIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

bool isLeaf(BinaryTreeNode<int>* node) {
    return (node != nullptr) && (node->left == nullptr) && (node->right == nullptr);
}

void printPathTillLeaf(BinaryTreeNode<int>* node, int k, string path) {
    if (node == nullptr) return;

    if (k == node->data && isLeaf(node)) {
        path += to_string(node->data);
        cout << path << endl;
        return;
    }

    printPathTillLeaf(node->left, k - node->data, path + to_string(node->data) + " ");
    printPathTillLeaf(node->right, k - node->data, path + to_string(node->data) + " ");
}

void rootToLeafPathsSumToK(BinaryTreeNode<int> *root, int k) {
    printPathTillLeaf(root, k, "");
}

int main() {
    initIO();
    BinaryTreeNode<int>* root = takeInput();
    int k;
    cin >> k;
    rootToLeafPathsSumToK(root, k);
    delete root;
    return 0;
}