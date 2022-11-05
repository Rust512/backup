#include "../BinaryTree.cpp"

using namespace std;

void initIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

BinaryTreeNode<int>* helper(int* input, int start, int end) {
    if (start > end) return nullptr;

    int mid = start + (end - start)/2;
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(input[mid]);

    root->left = helper(input, start, mid - 1);
    root->right = helper(input, mid + 1, end);

    return root;
}

BinaryTreeNode<int>* constructTree(int* input, int n) {
    return helper(input, 0, n - 1);
}

int main() {
    initIO();
    int size; cin >> size;
    int* input = new int[size];

    for (int i = 0; i < size; i++) {
        cin >> input[i];
    }

    BinaryTreeNode<int>* root = constructTree(input, size);

    preOrder(root);

    return 0;
}