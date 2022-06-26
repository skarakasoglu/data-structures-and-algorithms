//
// Created by Süleyman Karakaşoğlu on 24.06.2022.
//

#include <vector>

int rob(std::vector<int> nums) {
    int n = nums.size();

    if (n == 0) return 0;
    if (n < 2) return *std::max_element(nums.begin(), nums.end());

    std::vector<int> dp(n);
    dp[0] = nums[0];
    dp[1] = std::max(nums[0], nums[1]);

    for (auto i = 2; i < n; i++) {
        dp[i] = std::max(dp[i - 1], nums[i] + dp[i - 2]);
    }

    return dp.back();
}

int coin_change(std::vector<int> coins, int amount) {
    std::vector<long long> dp(amount + 1);

    dp[0] = 0;
    for (auto i = 1; i <= amount; i++) {
        dp[i] = std::numeric_limits<int>::max();
        for (const auto& coin: coins) {
            dp[i] = std::min(dp[i], i >= coin ? 1 + dp[i - coin] : std::numeric_limits<int>::max());
        }
    }

    return dp[amount] == std::numeric_limits<int>::max() ? -1 : dp[amount];
}