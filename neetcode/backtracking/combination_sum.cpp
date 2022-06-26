//
// Created by Süleyman Karakaşoğlu on 26.06.2022.
//

#include <vector>

void dfs(std::vector<std::vector<int>>& combinations, std::vector<int>& current_combination, int index, int sum, std::vector<int>& candidates, int target) {
    if (target == sum) {
        std::vector<int> res(current_combination);
        combinations.emplace_back(res);
        return;
    }
    if ((index >= candidates.size()) || sum > target) return;

    current_combination.emplace_back(candidates[index]);
    dfs(combinations, current_combination, index, sum + candidates[index], candidates, target);
    current_combination.pop_back();
    dfs(combinations, current_combination, index + 1, sum, candidates, target);
}

std::vector<std::vector<int>> combinationSum(std::vector<int>& candidates, int target) {
    std::vector<std::vector<int>> res;
    std::vector<int> comb;
    dfs(res, comb, 0, 0, candidates, target);
    return res;
}