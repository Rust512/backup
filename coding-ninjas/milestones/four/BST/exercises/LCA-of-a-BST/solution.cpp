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

inline int encode(int left, const int val, int right) {
    if (left > right) swap(left, right);

    if (val < left) return -1;
    else if ((val == left) || (val == right) || (val > left && val < right)) return 0;
    else return 1;
}

int getLCA(BinaryTreeNode<int>* root ,int val1 ,int val2){
    if (root == nullptr) return -1;

    switch(encode(val1, root->data, val2)) {
        case -1: return getLCA(root->right, val1, val2);
        case  0: return root->data;
        case  1: return getLCA(root->left, val1, val2);
        default: return -1;
    }

    return -1;
}

int main() {
    initIO();
    BinaryTreeNode<int>* root = takeInput();
    int a, b;
    cin >> a >> b;
    cout << getLCA(root, a, b);
    return 0;
}