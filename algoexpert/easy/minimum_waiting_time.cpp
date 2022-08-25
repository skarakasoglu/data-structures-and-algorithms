//
// Created by Süleyman Karakaşoğlu on 19.08.2022.
//

#include <vector>

using namespace std;

int minimumWaitingTime(vector<int> queries) {
    // Write your code here.
    std::sort(queries.begin(), queries.end());
    int total_waiting_time = 0, prefix_sum = 0;
    for (auto i = 1; i < queries.size(); i++) {
        auto query_waiting_time = prefix_sum + queries[i - 1];
        prefix_sum += queries[i - 1];
        total_waiting_time += query_waiting_time;
    }
    return total_waiting_time;
}
