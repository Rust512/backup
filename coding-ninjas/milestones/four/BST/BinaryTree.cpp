#include <iostream>
#include <queue>

template <typename T>
class BinaryTreeNode {
public:
    T data;
    BinaryTreeNode<T>* left;
    BinaryTreeNode<T>* right;

    BinaryTreeNode(T data) {
        this->data = data;
        this->left = nullptr;
        this->right = nullptr;
    }

    ~BinaryTreeNode() {
        delete this->left;
        delete this->right;
    }
};

BinaryTreeNode<int>* takeInput() {
    int rootData;
    std::cin >> rootData;
    if (rootData == -1) {
        return NULL;
    }
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);
    std::queue<BinaryTreeNode<int>*> q;
    q.push(root);
    while (!q.empty()) {
        BinaryTreeNode<int>* currentNode = q.front();
        q.pop();
        int leftChild, rightChild;
        std::cin >> leftChild;
        if (leftChild != -1) {
            BinaryTreeNode<int>* leftNode = new BinaryTreeNode<int>(leftChild);
            currentNode->left = leftNode;
            q.push(leftNode);
        }

        std::cin >> rightChild;
        if (rightChild != -1) {
            BinaryTreeNode<int>* rightNode =
                new BinaryTreeNode<int>(rightChild);
            currentNode->right = rightNode;
            q.push(rightNode);
        }
    }
    return root;
}

void preOrder(BinaryTreeNode<int>* root) {
    if (root == NULL) {
        return;
    }

    std::cout << root->data << " ";

    preOrder(root->left);
    preOrder(root->right);
}

void postOrder(BinaryTreeNode<int>* root) {
    if (root == NULL) {
        return;
    }

    postOrder(root->left);
    postOrder(root->right);
    std::cout << root->data << " ";
}

void inOrder(BinaryTreeNode<int>* root) {
    if (root == NULL) {
        return;
    }

    inOrder(root->left);
    std::cout << root->data << " ";
    inOrder(root->right);
}

void printLevelATNewLine(BinaryTreeNode<int>* root) {
    std::queue<BinaryTreeNode<int>*> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty()) {
        BinaryTreeNode<int>* first = q.front();
        q.pop();
        if (first == NULL) {
            if (q.empty()) {
                break;
            }
            std::cout << '\n';
            q.push(NULL);
            continue;
        }
        std::cout << first->data << " ";
        if (first->left != NULL) {
            q.push(first->left);
        }
        if (first->right != NULL) {
            q.push(first->right);
        }
    }
}
