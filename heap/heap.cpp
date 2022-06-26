//
// Created by Süleyman Karakaşoğlu on 24.06.2022.
//

#include <vector>

class heap{
private:
    std::vector<int> elements;

    void buildHeap(std::vector<int> arr) {
        for (auto i = 0; i < arr.size(); i++) {
            push(arr[i]);
        }
    }

    void bubleUp(int index) {
        auto parent = (index - 1) / 2;

        while (parent >= 0 && elements[parent] > elements[index]) {
            std::swap(elements[parent], elements[index]);
            index = parent;
            parent = (index - 1) / 2;
        }
    }

    void bubleDown(int index) {
        while (!isLeafNode(index)) {
            int left_child = 2 * index + 1, right_child = 2 * index + 2;
            int smallest_child = left_child;

            if (right_child < elements.size() && elements[right_child] < elements[left_child]) {
                smallest_child = right_child;
            }

            if (elements[smallest_child] < elements[index]) {
                std::swap(elements[smallest_child], elements[index]);
                index = smallest_child;
            } else {
                break;
            }
        }
    }

    bool isLeafNode(int index) {
        return 2 * index + 1 >= elements.size();
    }
public:
    heap() {}
    heap(std::vector<int> arr) {
        buildHeap(arr);
    }

    void push(int elem) {
        elements.emplace_back(elem);
        bubleUp(elements.size() - 1);
    }

    int top() {
        return elements[0];
    }

    void pop() {
        elements[0] = elements[elements.size() - 1];
        bubleDown(0);
        elements.pop_back();
    }
};

std::vector<int> heap_top_3(std::vector<int> arr) {
    heap max_heap(arr);

    std::vector<int> res;
    for (auto i = 0; i < 3; i++) {
        res.emplace_back(max_heap.top());
        max_heap.pop();
    }

    return res;
}