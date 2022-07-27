//
// Created by Süleyman Karakaşoğlu on 27.07.2022.
//

#include <vector>

int max_network_rank(std::vector<int> starts, std::vector<int> ends, int n) {
    std::vector<int> network_ranks(n, 0);
    auto m = starts.size();

    auto max_network_rank = 0;

    for (auto i = 0; i < m; i++) {
        network_ranks[starts[i] - 1]++;
        network_ranks[ends[i] - 1]++;
    }

    for (auto i = 0; i < m; i++) {
        auto total_network_rank = network_ranks[starts[i] - 1] + network_ranks[ends[i] - 1] - 1;
        max_network_rank = std::max(max_network_rank, total_network_rank);
    }
    return max_network_rank;
}