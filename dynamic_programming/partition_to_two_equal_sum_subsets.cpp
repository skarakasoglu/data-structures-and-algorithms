//
// Created by Süleyman Karakaşoğlu on 10.07.2022.
//

#include <vector>
#include <numeric>

bool dfs(int left_sum, int right_sum, std::vector<std::vector<int>>& memo, std::vector<int> nums, int index) {
    if (index >= nums.size()) {
        return left_sum == right_sum;
    }

    if (memo[index][left_sum] == 0) {
        auto left_tree = dfs(left_sum + nums[index], right_sum, memo, nums, index + 1);
        memo[index][left_sum] = left_tree ? 2 : 1;
    }

    if (memo[index][right_sum] == 0) {
        auto right_tree = dfs(left_sum, right_sum + nums[index], memo, nums, index + 1);
        memo[index][right_sum] = right_tree ? 2 : 1;
    }

    return memo[index][left_sum] == 2 || memo[index][right_sum] == 2;
}

bool can_partition(std::vector<int> nums) {

    auto total_sum = std::accumulate(nums.begin(), nums.end(), 0);
    std::vector<std::vector<int>> memo(nums.size() + 1, std::vector<int>(total_sum + 1, 0));
    return dfs(0, 0, memo, nums, 0);
}