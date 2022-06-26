//
// Created by Süleyman Karakaşoğlu on 26.06.2022.
//

#include <vector>
#include <cmath>
#include <queue>

std::vector<std::vector<int>> kClosest(std::vector<std::vector<int>>& points, int k) {
    auto compare_points = [](std::vector<int>& p1, std::vector<int>& p2) {
        auto p1_dist = std::sqrt(std::pow(p1[0], 2.0) + std::pow(p1[1], 2.0));
        auto p2_dist = std::sqrt(std::pow(p2[0], 2.0) + std::pow(p2[1], 2.0));

        return p1_dist > p2_dist;
    };

    std::priority_queue<std::vector<int>, std::vector<std::vector<int>>, decltype(compare_points)> heap(points.begin(), points.end(), compare_points);
    std::vector<std::vector<int>> res(k);

    for (auto i = 0; i < k; i++) {
        auto top = heap.top();
        heap.pop();
        res[i] = top;
    }

    return res;
}