//
// Created by Süleyman Karakaşoğlu on 12.07.2022.
//

#include <vector>

int knapsack(std::vector<int> weights, std::vector<int> values, int max_weight) {
    int n = weights.size();
    std::vector<std::vector<int>> dp(n + 1, std::vector<int>(max_weight + 1, std::numeric_limits<int>::min()));

    auto max_val = 0;
    dp[0][0] = 0;
    for (auto i = 1; i <= n; i++) {
        for (auto j = 0; j <= max_weight; j++) {
            if (dp[i - 1][j] == std::numeric_limits<int>::min()) continue;

            dp[i][j] = dp[i - 1][j];
            if (j + weights[i - 1] <= max_weight) {
                dp[i][j + weights[i - 1]] = dp[i - 1][j] + values[i - 1];
                max_val = std::max(max_val, dp[i][j + max_weight]);
            }
        }
    }

    return dp[n][max_weight];
}