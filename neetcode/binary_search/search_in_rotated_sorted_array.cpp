//
// Created by Süleyman Karakaşoğlu on 26.06.2022.
//

#include <vector>

int search(std::vector<int>& nums, int target) {
    int left = 0, right = nums.size() - 1;

    while (left <= right) {
        auto mid = (left + right) / 2;

        if (target == nums[mid]) return mid;

        if (nums[left] <= nums[mid]) {
            if (target > nums[mid] || target < nums[left]) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        } else {
            if (target < nums[mid] || target > nums[right]) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
    }

    return -1;
}