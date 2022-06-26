//
// Created by Süleyman Karakaşoğlu on 21.06.2022.
//

struct ListNode{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* reverseList(ListNode* head) {
    if (head == nullptr) return head;

    ListNode* previous;
    ListNode* reversed_head;

    while (head != nullptr) {
        auto temp = head->next;
        head->next = previous;
        previous = head;
        reversed_head = head;
        head = temp;
    }

    return reversed_head;
}