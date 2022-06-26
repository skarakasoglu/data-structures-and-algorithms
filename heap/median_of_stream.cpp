//
// Created by Süleyman Karakaşoğlu on 24.06.2022.
//
#include <queue>

class MedianOfStream {
private:
    std::priority_queue<float, std::vector<float>, std::greater<>> min_heap;
    std::priority_queue<float> max_heap;

    void balance() {
        if (max_heap.size() < min_heap.size()) {
            max_heap.push(min_heap.top());
            min_heap.pop();
        } else if (min_heap.size() + 1 < max_heap.size()) {
            min_heap.push(max_heap.top());
            max_heap.pop();
        }
    }
public:
    void add_number(float num) {
        if (max_heap.empty() || num < max_heap.top()) {
            max_heap.push(num);
        } else {
            min_heap.push(num);
        }
        balance();
    }

    float get_median() {
        if (max_heap.empty() && min_heap.empty()) return 0;

        if (max_heap.size() > min_heap.size()) return max_heap.top();
        if (min_heap.size() > max_heap.size()) return min_heap.top();
        return (max_heap.top() + min_heap.top()) / 2.0;
    }
};