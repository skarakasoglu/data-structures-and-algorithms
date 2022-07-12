//
// Created by Süleyman Karakaşoğlu on 12.07.2022.
//

#include <vector>

int f(int bitmask, int cur, std::vector<std::vector<int>> graph, std::vector<std::vector<int>>& dp) {
    if (bitmask == (1 << graph.size()) - 1) return 0;
    if (dp[bitmask][cur] != 0) return dp[bitmask][cur];

    int ans = 0x3f3f3f3f;
    for(int i = 0; i < graph[cur].size(); i++) {
        if ((bitmask & (1 << i)) == 0 && graph[cur][i] != 0) {
            ans = std::min(ans, graph[cur][i] + f((bitmask | (1 << i)), i, graph, dp));
        }
    }

    return dp[bitmask][cur] = ans;
}

int min_cost_to_visit_every_node(std::vector<std::vector<int>> graph) {
    std::vector<std::vector<int>> dp(1 << graph.size(), std::vector<int>(graph.size()));
    int ans = f(1, 0, graph, dp);
    return ans == 0x3f3f3f3f ? -1 : ans;
}