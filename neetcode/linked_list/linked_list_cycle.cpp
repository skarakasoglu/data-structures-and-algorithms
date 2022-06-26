//
// Created by Süleyman Karakaşoğlu on 25.06.2022.
//
 struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

bool hasCycle(ListNode* head) {
    auto fast = head;
    auto slow = head;

    while (fast && fast->next) {
        fast = fast->next->next;
        slow = slow->next;

        if (fast == slow) return true;
    }

    return false;
}