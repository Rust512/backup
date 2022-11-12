#include "../../BinaryTree.cpp"
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

int helper(BinaryTreeNode<int>* node, int greaterSum) {
    if (node == nullptr) return 0;

    int rightSide =  helper(node->right, greaterSum);
    node->data += rightSide + greaterSum;
    int leftSide = helper(node->left, node->data);

    return node->data - greaterSum + leftSide;

}

void replaceWithLargerNodesSum(BinaryTreeNode<int>* root) {
    if (root == nullptr) return;
    int sum = helper(root, 0);
}

int main() {
    initIO();
    BinaryTreeNode<int> *root = takeInput();
    replaceWithLargerNodesSum(root);
    printLevelATNewLine(root);
    return 0;
}