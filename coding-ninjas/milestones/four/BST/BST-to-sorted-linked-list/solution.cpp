#include "../BinaryTree.cpp"
#include "../LinkedList.cpp"

using namespace std;

void initIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

pair<Node<int>*, Node<int>*> helper(BinaryTreeNode<int>* root) {
    if (root == nullptr) {
        return make_pair(nullptr, nullptr);
    }

    pair<Node<int>*, Node<int>*> left = helper(root->left);
    pair<Node<int>*, Node<int>*> right = helper(root->right);

    Node<int>* mid = new Node<int>(root->data);
    mid->next = right.first;
    if (left.first == nullptr) {
        return make_pair(mid, (right.first == nullptr) ? mid: right.second);
    } else {
        left.second->next = mid;
        return make_pair(left.first, (right.first == nullptr) ? mid: right.second);
    }
}

Node<int>* constructLinkedList(BinaryTreeNode<int>* root) {
    pair<Node<int>*, Node<int>*> output = helper(root);
    return output.first;
}

int main() {
    initIO();
    BinaryTreeNode<int>* root = takeInput();
    Node<int>* head = constructLinkedList(root);

    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    return 0;
}