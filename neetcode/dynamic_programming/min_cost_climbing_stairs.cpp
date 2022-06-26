//
// Created by Süleyman Karakaşoğlu on 25.06.2022.
//

#include <vector>


int minCostClimbingStairs(std::vector<int>& cost) {
    int n = cost.size();
    std::vector<int> dp(n + 1);

    dp[0] = 0;
    dp[1] = 0;

    for(auto i = 2; i <= n; i++) {
        dp[i] = std::min(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2]);
    }

    return dp.back();
}