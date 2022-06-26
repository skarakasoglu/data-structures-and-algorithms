//
// Created by Süleyman Karakaşoğlu on 21.06.2022.
//

#include <vector>
#include <unordered_set>

bool containsDuplicate(std::vector<int>& nums) {
    std::unordered_set<int> num_counts;

    for (const auto& num: nums) {
        if (num_counts.count(num)) return true;

        num_counts.emplace(num);
    }

    return false;
}