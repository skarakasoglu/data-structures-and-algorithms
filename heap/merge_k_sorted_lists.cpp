//
// Created by Süleyman Karakaşoğlu on 24.06.2022.
//

#include <queue>

struct Element{
    int val;
    std::vector<int> list;
    int head_index;

    Element(int val, std::vector<int> list, int head_index) : val(val), list(list), head_index(head_index) {}
};

std::vector<int> merge_k_sorted_lists(std::vector<std::vector<int>> lists) {
    auto compare_elements = [](const Element& e1, const Element& e2)-> bool {
        return e1.val > e2.val;
    };
    std::priority_queue<Element, std::vector<Element>, decltype(compare_elements)> heap(compare_elements);

    for (const auto& list: lists) {
        Element e(list[0], list, 0);
        heap.push(e);
    }

    std::vector<int> res;
    while (!heap.empty()) {
        Element cur = heap.top();
        res.emplace_back(cur.val);

        int head_index = cur.head_index + 1;
        if (head_index < cur.list.size()) {
            Element new_e(cur.list[head_index], cur.list, head_index);
            heap.push(new_e);
        }

        heap.pop();
    }

    return res;
}