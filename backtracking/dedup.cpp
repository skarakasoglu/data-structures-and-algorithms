//
// Created by Süleyman Karakaşoğlu on 17.06.2022.
//

#include <vector>

void combination_dfs(std::vector<std::vector<int>>& combs, std::vector<int> comb, int sum, int start, std::vector<int> candidates, int target) {
   if (sum == target) {
       std::vector<int> list(comb);
       combs.emplace_back(comb);
    }

    if (sum < target) {
        for (auto i = start; i < candidates.size(); i++) {
            sum += candidates[i];
            if (sum > target) break;
            comb.emplace_back(candidates[i]);
            combination_dfs(combs, comb, sum, i, candidates, target);
            comb.pop_back();
            sum -= candidates[i];
        }
    }
}

std::vector<std::vector<int>> combination_sum(std::vector<int> candidates, int target) {
    std::vector<std::vector<int>> res;
    combination_dfs(res, {}, 0, 0, candidates, target);
    return res;
}

void subset_dfs(std::vector<std::vector<int>>& res, std::vector<int> seq, int i, std::vector<int> nums) {
    if (i == nums.size()) {
        return;
    }

    seq.emplace_back(nums[i]);
    std::vector<int> list(seq);
    res.emplace_back(list);
    subset_dfs(res, seq, i + 1, nums);
    seq.pop_back();
    subset_dfs(res, seq, i + 1, nums);
}

std::vector<std::vector<int>> subsets(std::vector<int> nums) {
    std::vector<std::vector<int>> res;
    subset_dfs(res, {}, 0, nums);
    return res;
}