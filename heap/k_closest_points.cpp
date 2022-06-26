//
// Created by Süleyman Karakaşoğlu on 24.06.2022.
//

#include <vector>
#include <queue>
#include <cmath>

std::vector<std::vector<int>> k_closest_points(std::vector<std::vector<int>> points, int k) {
    auto compare_points = [](std::vector<int>& p1, std::vector<int>& p2) {
        auto distance_formula = [](std::vector<int>& point) -> double {
            return std::sqrt(std::pow(point[0], 2) + std::pow(point[1], 2));
        };

        auto p1_distance_from_origin = distance_formula(p1);
        auto p2_distance_from_origin = distance_formula(p2);

        return p1_distance_from_origin > p2_distance_from_origin;
    };

    std::priority_queue<std::vector<int>, std::vector<std::vector<int>>, decltype(compare_points)> heap(points.begin(), points.end(), compare_points);

    std::vector<std::vector<int>> res;
    for (auto i = 0; i < k; i++) {
        res.emplace_back(heap.top());
        heap.pop();
    }

    return res;
}