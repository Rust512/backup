template <typename T>
class Node {
public:
    T data;
    Node<T> *next;

    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }

    ~Node() {
        if (next) {
            delete this->next;
        }
    }
};