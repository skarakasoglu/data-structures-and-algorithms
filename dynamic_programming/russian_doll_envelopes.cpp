//
// Created by Süleyman Karakaşoğlu on 10.07.2022.
//

#include <vector>

int max_layers(std::vector<std::vector<int>> envelopes) {
    std::vector<int> dp(envelopes.size(), 0);

    std::sort(envelopes.begin(), envelopes.end());

    auto max = 0;
    for (auto i = 0; i < envelopes.size(); i++) {
        auto width = envelopes[i][0];
        auto height = envelopes[i][1];

        for (auto j = 0; j < envelopes.size(); j++) {
            if (i == j) continue;

            auto container_width = envelopes[j][0];
            auto container_height = envelopes[j][1];

            if (container_width < width && container_height < height) {
                dp[i] = std::max(dp[i], dp[j] + 1);
            }
        }

        max = std::max(max, dp[i]);
    }

    return max;
}