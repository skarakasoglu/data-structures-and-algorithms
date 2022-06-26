//
// Created by Süleyman Karakaşoğlu on 21.06.2022.
//

#include <vector>
#include <unordered_map>

std::vector<int> twoSum(std::vector<int>& nums, int target) {
    std::unordered_map<int, int> diff_indexes;

    for (auto i = 0; i < nums.size(); i++) {
        auto num_it = diff_indexes.find(nums[i]);
        if (num_it != diff_indexes.end()) {
            return {num_it->second, i};
        }

        diff_indexes[target - nums[i]] = i;
    }

    return {};
}