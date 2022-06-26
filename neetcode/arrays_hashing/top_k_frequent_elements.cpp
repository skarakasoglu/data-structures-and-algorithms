//
// Created by Süleyman Karakaşoğlu on 25.06.2022.
//

#include <vector>
#include <map>

std::vector<int> topKFrequent(std::vector<int>& nums, int k) {
    if (nums.size() <= 1) return nums;

    std::vector<int> res(k);
    std::vector<std::vector<int>> occurrences(nums.size() + 1);
    std::map<int, int> element_frequencies;

    for (const auto& elem: nums) {
        element_frequencies[elem]++;
    }

    for (auto it = element_frequencies.begin(); it != element_frequencies.end(); it++) {
        occurrences[it->second].emplace_back(it->first);
    }

    int counter = 0;
    for (auto i = nums.size(); i >= 0; i--) {
        if (occurrences[i].empty()) continue;

        for (auto j = 0; j < occurrences[i].size(); j++) {
            res[counter] = occurrences[i][j];
            counter++;

            if (counter >= k) return res;
        }
    }

    return res;
}