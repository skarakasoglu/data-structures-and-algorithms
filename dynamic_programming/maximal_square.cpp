//
// Created by Süleyman Karakaşoğlu on 4.07.2022.
//

#include <vector>
#include <cmath>

int maximal_square(std::vector<std::vector<int>> matrix) {
    int m = matrix.size();
    int n = matrix[0].size();
    auto best = 0;

    std::vector<std::vector<int>> dp(m, std::vector<int>(n, 0));

    for (auto i = 0; i < m; i++) {
        dp[i][0] = matrix[i][0];
        best = std::max(best, dp[i][0]);
    }

    for (auto i = 0; i < n; i++) {
        dp[0][i] = matrix[0][i];
        best = std::max(best, dp[0][i]);
    }

    for (auto i = 1; i < m; i++) {
        for (auto j = 1; j < n; j++) {
            if (matrix[i][j] == 0) continue;
            dp[i][j] = 1 + std::min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]});
            best = std::max(best, dp[i][j]);
        }
    }

    return best * best;
}