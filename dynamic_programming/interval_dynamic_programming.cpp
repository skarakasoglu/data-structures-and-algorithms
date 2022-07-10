//
// Created by Süleyman Karakaşoğlu on 10.07.2022.
//

#include <vector>

int coin_game(std::vector<int> coins) {
    auto n = coins.size();
    std::vector<int> prefix_sum(n + 1, 0);
    for (auto i = 1; i <= n; i++) {
        prefix_sum[i] = prefix_sum[i - 1] + coins[i - 1];
    }

    std::vector<std::vector<int>> dp(n + 1, std::vector<int>(n + 1, 0));
    for (auto size = 0; size < n; size++) {
        for (auto l = 1; l + size <= n; l++) {
            auto r = l + size;
            if (l == r) {
                dp[l][r] = prefix_sum[r] - prefix_sum[l - 1];
            } else {
                dp[l][r] = prefix_sum[r] - prefix_sum[l - 1] - std::min(dp[l + 1][r], dp[l][r - 1]);
            }
        }
    }

    return dp[1][n];
}