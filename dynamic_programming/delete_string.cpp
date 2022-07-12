//
// Created by Süleyman Karakaşoğlu on 12.07.2022.
//

#include <vector>
#include <string>

int delete_string(std::vector<int> costs, std::string s1, std::string s2) {
    int dp[1001][1001], n = s1.length(), m = s2.length();

    for (auto i = 1; i <= n; i++) dp[i][0] = dp[i - 1][0] + costs[s1[i - 1] - 'a'];
    for (auto j = 1; j <= m; j++) dp[0][j] = dp[0][j - 1] + costs[s2[j - 1] - 'a'];

    for (auto i = 1; i <= n; i++) {
        for (auto j = 1; j <= m; j++) {
            if (s1[i - 1] == s2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1];
            } else {
                dp[i][j] = std::min(dp[i][j - 1] + costs[s2[j - 1] - 'a'], dp[i - 1][j] + costs[s1[i - 1] - 'a']);
            }
        }
    }

    return dp[n][m];
}