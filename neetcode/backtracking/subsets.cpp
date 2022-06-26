//
// Created by Süleyman Karakaşoğlu on 26.06.2022.
//

#include <vector>

void dfs(std::vector<std::vector<int>>& combinations, std::vector<int> current_combination, std::vector<bool>& visited, int index, std::vector<int>& nums) {
    if (index >= nums.size()) return;

    for (auto i = index; i  < nums.size(); i++) {
        current_combination.emplace_back(nums[i]);
        dfs(combinations, current_combination, visited, i + 1, nums);
        combinations.emplace_back(current_combination);
        current_combination.pop_back();
    }
}

std::vector<std::vector<int>> subsets(std::vector<int>& nums) {
    std::vector<std::vector<int>> res;
    res.emplace_back(std::vector<int>{});
    std::vector<bool> visited(nums.size(), false);
    dfs(res, {}, visited, 0, nums);
    return res;
}