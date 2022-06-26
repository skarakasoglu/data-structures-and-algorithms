//
// Created by Süleyman Karakaşoğlu on 26.06.2022.
//

#include <vector>
#include <queue>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};



ListNode* mergeKLists(std::vector<ListNode*> lists) {
    if (lists.empty()) return nullptr;

    auto compare_nodes = [](const ListNode* l1, const ListNode* l2) -> bool {
        return l1->val > l2->val;
    };
    std::priority_queue<ListNode*, std::vector<ListNode*>, decltype(compare_nodes)> heap(compare_nodes);

    for (auto list: lists) {
        if (list)
            heap.push(list);
    }

    ListNode* merged_head = nullptr;
    ListNode* current = nullptr;
    while (!heap.empty()) {
        auto top = heap.top();
        heap.pop();

        if (!merged_head) {
            merged_head = top;
            current = top;
        } else {
            current->next = top;
            current = current->next;
        }

        if (top->next) {
            heap.push(top->next);
        }
    }

    return merged_head;
}