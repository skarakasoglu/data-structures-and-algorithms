//
// Created by Süleyman Karakaşoğlu on 30.06.2022.
//

#include <vector>


int unique_paths(int m, int n) {
    std::vector<std::vector<int>> dp(m, std::vector<int>(n, 0));

    for (auto i = 0; i < m; i++) {
        dp[i][0] = 1;
    }

    for (auto i = 0; i < n; i++) {
        dp[0][i] = 1;
    }

    for (auto i = 1; i < m; i++) {
        for (auto j = 1; j < n; j++) {
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        }
    }

    return dp[m - 1][n - 1];
}