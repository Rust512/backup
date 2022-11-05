#include "../../BinaryTree.cpp"

using namespace std;

void initIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

void insertDuplicateNode(BinaryTreeNode<int>* node) {
    if (node == nullptr) {
        return;
    }

    BinaryTreeNode<int>* duplicate = new BinaryTreeNode<int>(node->data);
    duplicate->left = node->left;
    node->left = duplicate;
    insertDuplicateNode(duplicate->left);
    insertDuplicateNode(node->right);
}

int main() {
    initIO();
    BinaryTreeNode<int>* root = takeInput();
    insertDuplicateNode(root);
    printLevelATNewLine(root);
    return 0;
}