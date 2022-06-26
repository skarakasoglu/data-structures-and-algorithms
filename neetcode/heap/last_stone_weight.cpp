//
// Created by Süleyman Karakaşoğlu on 25.06.2022.
//

#include <queue>
#include <vector>

int lastStoneWeight(std::vector<int>& stones) {
    std::priority_queue<int> heap(stones.begin(), stones.end());

    while (heap.size() > 1) {
        int y = heap.top();
        heap.pop();
        int x = heap.top();
        heap.pop();

        if (x == y) continue;

        y = y - x;
        heap.push(y);
    }

    return heap.empty() ? 0 : heap.top();
}