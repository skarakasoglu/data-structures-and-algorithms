//
// Created by Süleyman Karakaşoğlu on 5.07.2022.
//

#include <vector>

int trap(std::vector<int>& height) {
    auto n = height.size();
    std::vector<int> left_walls(n, 0);
    std::vector<int> right_walls(n, 0);

    auto max_left_wall = 0;
    for (auto i = 0; i < n; i++) {
        left_walls[i] = max_left_wall;
        max_left_wall = std::max(max_left_wall, height[i]);
    }

    auto max_right_wall = 0;
    for (int i = n - 1; i >= 0; i--) {
        right_walls[i] = max_right_wall;
        max_right_wall = std::max(max_right_wall, height[i]);
    }

    auto trapped_count = 0;
    for (auto i = 0; i < n; i++) {
        auto trapping_height = std::min(left_walls[i], right_walls[i]);
        if (height[i] < trapping_height) {
            trapped_count += trapping_height - height[i];
        }
    }

    return trapped_count;
}