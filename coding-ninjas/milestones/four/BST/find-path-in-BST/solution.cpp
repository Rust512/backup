#include "../BinaryTree.cpp"
#include <vector>

using namespace std;

void initIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

inline int compare(int a, int b) {
    return (a < b) ? -1 : (a > b);
}

vector<int>* getPath(BinaryTreeNode<int> *root , int data) {
    if (root == nullptr) {
        return nullptr;
    }

    vector<int>* res = nullptr;

    switch(compare(data, root->data)) {
        case -1: {res = getPath(root->left, data); break;}
        case 0:  {res = new vector<int>(); break;}
        case 1:  {res = getPath(root->right, data); break;}
    }

    if (res == nullptr) {
        return nullptr;
    }

    res->push_back(root->data);
    return res;
}

int main() {
    initIO();
    BinaryTreeNode<int> *root = takeInput();
    int k;
    cin >> k;
    vector<int> *output = getPath(root, k);

    if (output != NULL) {
        for (int i = 0; i < output->size(); i++) {
            cout << output->at(i) << " ";
        }
    }

    delete root;
    return 0;
}