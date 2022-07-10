//
// Created by Süleyman Karakaşoğlu on 10.07.2022.
//

#include <vector>

int longest_sub_len(std::vector<int> nums) {
    std::vector<int> dp(nums.size(), 1);

    auto max_len = 0;
    for (auto i = 1; i < nums.size(); i++) {
        for (auto j = i - 1; j >= 0; j--) {
            if (nums[j] < nums[i]) {
                dp[i] = std::max(dp[i], dp[j] + 1);
                max_len = std::max(max_len, dp[i]);
            }
        }
    }

    return max_len;
}