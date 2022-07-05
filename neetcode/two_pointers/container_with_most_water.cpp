//
// Created by Süleyman Karakaşoğlu on 5.07.2022.
//

#include <vector>

int maxArea(std::vector<int>& height) {

    auto l = 0;
    auto r = height.size() - 1;

    auto max_area = 0;
    while (l < r) {
        auto container_width = r - l;
        auto container_height = std::min(height[l], height[r]);
        auto area = (int)container_width * container_height;

        max_area = std::max(max_area, area);

        if (height[l] <= height[r]) {
            l++;
        } else {
            r--;
        }
    }

    return max_area;
}