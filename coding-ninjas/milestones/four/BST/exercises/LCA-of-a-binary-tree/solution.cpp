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

inline int encode(const bool a, const bool b) {
    return (a << 1) + b;
}

BinaryTreeNode<int>* helper(BinaryTreeNode<int>* root, int a, int b) {
    if (root == nullptr) return nullptr;
    if (root->data == a || root->data == b) return root;

    BinaryTreeNode<int>* leftOutput = helper(root->left, a, b);
    BinaryTreeNode<int>* rightOutput = helper(root->right, a, b);

    switch(encode(leftOutput, rightOutput)) {
        case 0: return nullptr;
        case 1: return rightOutput;
        case 2: return leftOutput;
        case 3: return root;
        default: return nullptr;
    }
}

int getLCA(BinaryTreeNode<int>* root, int a, int b) {
    BinaryTreeNode<int>* ancestor = helper(root, a, b);
    return (ancestor == nullptr) ? -1 : ancestor->data;
}

int main() {
    initIO();
    BinaryTreeNode<int>* root = takeInput();
    int a, b;
    cin >> a >> b;
    cout << getLCA(root, a, b);
    delete root;
    return 0;
}