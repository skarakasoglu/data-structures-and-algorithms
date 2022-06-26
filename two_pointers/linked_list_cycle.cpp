//
// Created by Süleyman Karakaşoğlu on 24.06.2022.
//


template <typename T>
struct Node {
    T val;
    Node<T>* next;

    explicit Node(T val, Node<T>* next = nullptr)
            : val{val}, next{next} {}

    ~Node() {
        delete next;
    }
};

bool has_cycle(Node<int>* nodes) {
    Node<int>* slow = nodes;
    Node<int>* fast = nodes;

    while (fast && fast->next) {
        fast = fast->next->next;
        slow = slow->next;

        if (slow == fast) {
            return true;
        }
    }

    return false;
}