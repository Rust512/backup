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

inline int compare(const int a, const int b) {
    return (a < b) ? -1 : (a > b);
}

inline int encode(const bool a, const bool b) {
    return (a << 1) + b;
}

class BST {
private:
    BinaryTreeNode<int>* insert(BinaryTreeNode<int>* node, int data) {
        if (node == nullptr) {
            return new BinaryTreeNode<int>(data);
        }

        if (data > node->data) {
            node->right = insert(node->right, data);
        } else {
            node->left = insert(node->left, data);
        }

        return node;
    }

    void printNode(BinaryTreeNode<int>* node) {
        if (node == nullptr) {
            return;
        }

        cout << node->data << ":";
        if (node->left) {
            cout << "L:" << node->left->data << ",";
        }

        if (node->right) {
            cout << "R:" << node->right->data;
        }

        cout << '\n';

        printNode(node->left);
        printNode(node->right);
    }

    bool search(BinaryTreeNode<int>* node, int data) {
        if (node == nullptr) {
            return false;
        }

        switch(compare(data, node->data)) {
            case -1: {return search(node->left, data);}
            case  0: {return true;}
            case  1: {return search(node->right, data);}
        }

        return false;
    }

    int findSmallest(BinaryTreeNode<int>* node) {
        BinaryTreeNode<int>* temp = node;
        while (temp->left != nullptr) {
            temp = temp->left;
        }

        return temp->data;
    }

    BinaryTreeNode<int>* remove(BinaryTreeNode<int>* node, int data) {
        if (node == nullptr) {
            return nullptr;
        }

        switch(compare(data, node->data)) {
            case -1: {node->left = this->remove(node->left, data); break;}
            case  1: {node->right = this->remove(node->right, data); break;}
            case  0: {
                switch(encode(node->left, node->right)) {
                    case 0: {
                        delete node;
                        return nullptr;
                    }
                    case 1: {
                        auto temp = node->right;
                        node->right = nullptr;
                        delete node;
                        return temp;
                    }
                    case 2: {
                        auto temp = node->left;
                        node->left = nullptr;
                        delete node;
                        return temp;
                    }
                    case 3: {
                        int minRight = findSmallest(node->right);
                        node->data = minRight;
                        node->right = this->remove(node->right, minRight);
                        return node;
                    }
                    default: break;
                }
            }
            default: break;
        }

        return node;
    }

public:
    BinaryTreeNode<int>* root;

    BST() {
        this->root = nullptr;
    }

    void remove(int data) {
        this->root = this->remove(this->root, data);
    }

    void print() {
        this->printNode(this->root);
    }

    void insert(int data) {
        this->root = this->insert(this->root, data);
    }

    bool search(int data) {
        return this->search(this->root, data);
    }
};

int main() {
    initIO();
    BST *tree = new BST();
    int choice, input, q;
    cin >> q;
    while (q--) {
        cin >> choice;
        switch (choice) {
            case 1:
                cin >> input;
                tree->insert(input);
                break;
            case 2:
                cin >> input;
                tree->remove(input);
                break;
            case 3:
                cin >> input;
                cout << ((tree->search(input)) ? "true\n" : "false\n");
                break;
            default:
                tree->print();
                break;
        }
    }
    return 0;
}