#include "../../BinaryTree.cpp"
#include <stack>

using namespace std;

void initIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

inline int encode(const int a, const int b) {
    return (a < b) ? -1 : (a > b);
}

void printNodesSumToS(BinaryTreeNode<int> *root, int s) {
    if (root == nullptr) return;
    stack<BinaryTreeNode<int>*> forw, rev;

    BinaryTreeNode<int> *rootForw = root, *rootRev = root, *currForw = nullptr, *currRev = nullptr;

    bool findForw = false, findRev = false;

    while (1) {
        if (!findForw) {
            while (rootForw != nullptr) {
                forw.push(rootForw);
                rootForw = rootForw->left;
            }
            currForw = forw.top();
            forw.pop();
            rootForw = currForw->right;
            findForw = true;
        }

        if (!findRev) {
            while (rootRev != nullptr) {
                rev.push(rootRev);
                rootRev = rootRev->right;
            }
            currRev = rev.top();
            rev.pop();
            rootRev = currRev->left;
            findRev = true;
        }

        if (currForw->data >= currRev->data) {
            break;
        }

        switch (encode(currForw->data + currRev->data, s)) {
            case -1: findForw = false; break;
            case  0: {
                cout << currForw->data << ' ' << currRev->data << endl;
                findForw = false; findRev = false;
                break;
            }
            case  1: findRev = false; break;
        }

    }
}

int main() {
    initIO();
    BinaryTreeNode<int> *root = takeInput();
    int s;
    cin >> s;
    printNodesSumToS(root, s);
    delete root;
    return 0;
}
