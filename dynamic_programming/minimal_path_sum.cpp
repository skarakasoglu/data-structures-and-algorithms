//
// Created by Süleyman Karakaşoğlu on 4.07.2022.
//

#include <vector>

int min_path_sum(std::vector<std::vector<int>> grid) {
    int m = grid.size();
    int n = grid[0].size();

    std::vector<std::vector<int>> dp(m, std::vector<int>(n, std::numeric_limits<int>::max()));

    dp[0][0] = grid[0][0];
    for (auto i = 1; i < m; i++) {
        dp[i][0] = dp[i - 1][0] + grid[i][0];
    }

    for (auto i = 1; i < n; i++) {
        dp[0][i] = dp[0][i - 1] + grid[0][i];
    }

    for (auto i = 1; i < m; i++) {
        for (auto j = 1; j < n; j++) {
            dp[i][j] = std::min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
        }
    }

    return dp[m - 1][n - 1];
};