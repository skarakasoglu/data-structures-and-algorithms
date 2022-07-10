//
// Created by Süleyman Karakaşoğlu on 10.07.2022.
//

#include <vector>
#include <numeric>
#include <set>

void generate_sum(std::set<int>& solutions, int sum, std::vector<std::vector<bool>>& memo, const std::vector<int>& weights, int index) {
    if (memo[index][sum]) return;
    if (index == 0) {
        solutions.emplace(sum);
        return;
    }

    memo[index][sum] = true;
    generate_sum(solutions, sum + weights[index - 1], memo, weights, index - 1);
    generate_sum(solutions, sum, memo, weights, index - 1);
}

std::vector<int> knapsack_weight_only(std::vector<int> weights) {
    std::set<int> res;

    auto total_sum = 0;
    for (int weight: weights) {
        total_sum += weight;
    }

    std::vector<std::vector<bool>> memo(weights.size() + 1, std::vector<bool>(total_sum + 1, false));

    generate_sum(res, 0, memo, weights, weights.size());
    return std::vector<int>(res.begin(), res.end());
}


std::vector<int> knapsack_weight_only_bottom_up(std::vector<int> weights) {
    auto total_sum = std::accumulate(weights.begin(), weights.end(), 0);
    std::vector<std::vector<bool>> dp(2, std::vector<bool>(total_sum + 1, false));
    std::set<int> sums = {0};

    dp[0][0] = true;
    for (auto i = 1; i <= weights.size(); i++) {
        for (auto j = 0; j <= total_sum; j++) {
            if (!dp[0][j]) continue;

            dp[1][j] = true;
            dp[1][j + weights[i - 1]] = true;
            sums.insert(j + weights[i - 1]);
        }

       for (auto j = 0; j < total_sum + 1; j++) {
           dp[0][j] = dp[1][j];
       }
    }

    return {sums.begin(), sums.end()};
}