//
// Created by Süleyman Karakaşoğlu on 21.06.2022.
//

#include "reverse_linked_list.cpp"


ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    auto dummy = new ListNode(0, nullptr);
    auto tail = dummy;

    while (list1 && list2) {
        if (list1->val < list2->val) {
            tail->next = list1;
            list1 = list1->next;
        } else {
            tail->next = list2;
            list2 = list2->next;
        }

        tail = tail->next;
    }

    if (list1) {
        tail->next = list1;
    } else if (list2) {
        tail->next = list2;
    }

    return dummy->next;
}