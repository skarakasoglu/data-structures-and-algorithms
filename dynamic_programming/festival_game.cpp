//
// Created by Süleyman Karakaşoğlu on 10.07.2022.
//

#include <vector>

long dfs(int l, int r, std::vector<std::vector<long>>& dp, std::vector<int> target) {
    if (dp[l][r] != 0) return dp[l][r];

    for (auto i = l; i <= r; i++) {
        long left_interval = i == l ? 0 : dfs(l, i - 1, dp, target);
        long right_interval = i == r ? 0 : dfs(i + 1, r, dp, target);
        long val = (l == 0 ? 1 : target[l - 1]) * target[i] * (r == target.size() - 1 ? 1 : target[r + 1]);
        dp[l][r] = std::max(dp[l][r], left_interval + right_interval + val);
    }

    return dp[l][r];
}

long long festival_game(std::vector<int> target) {
    int n = target.size();
    std::vector<std::vector<long>> dp(n, std::vector<long>(n));
    return dfs(0, n - 1, dp, target);
}