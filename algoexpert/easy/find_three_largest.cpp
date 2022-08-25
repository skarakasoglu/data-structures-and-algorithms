//
// Created by Süleyman Karakaşoğlu on 25.08.2022.
//
#include <vector>
#include <queue>
using namespace std;

vector<int> findThreeLargestNumbers(vector<int> array) {
    // Write your code here.
    std::priority_queue<int, vector<int>, greater<>> heap;

    for (auto i = 0; i < array.size(); i++) {
        if (heap.size() < 3) {
            heap.push(array[i]);
            continue;
        }

        auto top = heap.top();
        if (top < array[i]) {
            heap.push(array[i]);

            if (heap.size() > 3) heap.pop();
        }
    }

    vector<int> res;
    while (!heap.empty()) {
        auto top = heap.top();
        res.emplace_back(top);
        heap.pop();
    }

    return res;
}
