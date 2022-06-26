//
// Created by Süleyman Karakaşoğlu on 25.06.2022.
//

#include <vector>
#include <queue>

class KthLargest {
private:
    std::priority_queue<int, std::vector<int>, std::greater<>> heap;
    int k;
public:
    KthLargest(int k, std::vector<int>& nums) {
        this->k = k;
        heap = std::priority_queue<int, std::vector<int>, std::greater<>>(nums.begin(), nums.end());

        while (heap.size() > k) {
            heap.pop();
        }
    }

    int add(int val) {
        if (heap.size() < k) {
            heap.push(val);
        } else if (val > heap.top()) {
            heap.push(val);
            heap.pop();
        }

        return heap.top();
    }
};