//
// Created by Süleyman Karakaşoğlu on 10.07.2022.
//

#include <vector>

int perfect_squares(int n) {
    std::vector<int> dp(n + 1, std::numeric_limits<int>::max());
    dp[0] = 0;

    for (auto i = 1; i * i <= n; i++) {
        auto cur = i * i;
        for (auto j = cur; j <= n; j++) {
            dp[j] = std::min(dp[j], dp[j - cur] + 1);
        }
    }

    return dp[n];
}