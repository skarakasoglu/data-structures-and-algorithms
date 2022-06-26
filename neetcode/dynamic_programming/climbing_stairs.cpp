//
// Created by Süleyman Karakaşoğlu on 25.06.2022.
//

#include <vector>

//memoization
int climbStairs(int n, int i, std::vector<int>& memo) {
    if (i == n) return 1;
    if (i > n) return 0;
    if (memo[i] != -1) return memo[i];

    int res = climbStairs(n, i + 1, memo) + climbStairs(n, i + 2, memo);
    memo[i] = res;
    return res;
}

int climbStairs(int n) {
    std::vector<int> memo(n, -1);
    return climbStairs(n, 0, memo);
}

int dynamicClimbStairs(int n) {
    int prev1 = 1;
    int prev2 = 1;
    int current = prev2;
    for (auto i = 2; i <= n; i++) {
        prev1 = prev2;
        prev2 = current;
        current = prev1 + prev2;
    }

    return current;
}