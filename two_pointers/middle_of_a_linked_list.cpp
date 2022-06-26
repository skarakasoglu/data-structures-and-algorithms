//
// Created by Süleyman Karakaşoğlu on 23.06.2022.
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

int middle_of_linked_list(Node<int>* head) {
    Node<int>* fast = head;
    Node<int>* slow = head;

    while (fast && fast->next) {
        fast = fast->next->next;
        slow = slow->next;
    }

    return slow->val;
}