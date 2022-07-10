//
// Created by Süleyman Karakaşoğlu on 10.07.2022.
//

#include <vector>

bool divisor_game(int n) {
    std::vector<bool> dp(n + 1, false);

    for (auto i = 1; i <= n; i++) {
        for (auto j = 1; j < i; j++) {
            if (i % j == 0 && !dp[i - j]) {
                dp[i] = true;
                break;
            }
        }
    }

    return dp[n];
}