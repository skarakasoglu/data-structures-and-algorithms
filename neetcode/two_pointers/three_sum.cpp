//
// Created by Süleyman Karakaşoğlu on 26.06.2022.
//

#include <vector>
#include <unordered_map>
#include <unordered_set>

std::vector<std::vector<int>> threeSum(std::vector<int>& nums) {
    std::sort(nums.begin(), nums.end());

    std::vector<std::vector<int>> res;
    for (auto i = 0; i < nums.size(); i++) {
        if (i > 0 && nums[i] == nums[i - 1]) continue;

        int left = i + 1, right = nums.size() - 1;
        while (left < right) {
            auto threeSum = nums[i] + nums[left] + nums[right];
            if (threeSum > 0) {
                right--;
            } else if (threeSum < 0) {
                left++;
            } else {
                res.emplace_back(std::vector<int>{nums[i], nums[left], nums[right]});
                left++;
                while (nums[left] == nums[left - 1] && left < right) {
                    left++;
                }
            }
        }
    }

    return res;
}