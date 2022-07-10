//
// Created by Süleyman Karakaşoğlu on 10.07.2022.
//

#include <vector>

int find_largest_subset(std::vector<int> nums) {
    std::vector<int> dp(nums.size(), 1);
    std::sort(nums.begin(), nums.end());

    auto max_count = 0;
    for (auto i = 0; i < nums.size(); i++) {
        for (auto j = i - 1; j >= 0; j-- ){
            if (nums[i] % nums[j] == 0) {
                dp[i] = std::max(dp[i], dp[j] + 1);
            }
        }

        max_count = std::max(max_count, dp[i]);
    }

    return max_count;
}