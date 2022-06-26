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

int kth_smallest(std::vector<std::vector<int>> matrix, int k) {
    auto compare_points = [](const Element& e1, const Element& e2) -> bool {
        return e1.val > e2.val;
    };

    std::priority_queue<Element, std::vector<Element>, decltype(compare_points)> heap(compare_points);
    for (const auto& list: matrix) {
        Element e(list[0], list, 0);
        heap.push(e);
    }

    int smallest = 0, counter = 1;
    while(!heap.empty()) {
        auto cur = heap.top();
        heap.pop();
        counter++;

        if (counter > k) {
            smallest = cur.val;
            break;
        }

        auto head_index = cur.head_index + 1;
        if (head_index < cur.list.size()) {
            Element new_elem(cur.list[head_index], cur.list, head_index);
            heap.push(new_elem);
        }

    }

    return smallest;
}