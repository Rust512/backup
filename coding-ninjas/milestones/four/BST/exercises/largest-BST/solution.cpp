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

class BSTData {
public:
    int minVal;
    int maxVal;
    bool isBST;
    int maxBSTHeight;

    BSTData(int minVal, int maxVal, bool isBST, int maxBSTHeight) {
        this->minVal = minVal;
        this->maxVal = maxVal;
        this->isBST = isBST;
        this->maxBSTHeight = maxBSTHeight;
    }
};

BSTData* helper(BinaryTreeNode<int>* node) {
    if (node == nullptr) return new BSTData(INT_MAX, INT_MIN, true, 0);

    BSTData* leftSide = helper(node->left);
    BSTData* rightSide = helper(node->right);

    bool isBSTWithRoot = (leftSide->isBST && (leftSide->maxVal <= node->data)) && (rightSide->isBST && (rightSide->minVal >= node->data));

    return new BSTData(min(min(leftSide->minVal, rightSide->minVal), node->data), 
                    max(max(leftSide->maxVal, rightSide->maxVal), node->data), isBSTWithRoot, 
                    max(leftSide->maxBSTHeight, rightSide->maxBSTHeight) + isBSTWithRoot);
}

int largestBSTSubtree(BinaryTreeNode<int> *root) {
    BSTData* result = helper(root);
    return result->maxBSTHeight;
}

int main() {
    initIO();
    BinaryTreeNode<int>* root = takeInput();
    cout << largestBSTSubtree(root);
    return 0;
}