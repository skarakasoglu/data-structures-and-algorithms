//
// Created by Süleyman Karakaşoğlu on 24.06.2022.
//

#include <queue>
#include <vector>

int find_kth_largest_element(std::vector<int> nums, int k) {
    std::priority_queue<int> heap(nums.begin(), nums.end());

    int elem = 0;
    for (auto i = 0; i < k; i++) {
        elem = heap.top();
        heap.pop();
    }

    return elem;
}