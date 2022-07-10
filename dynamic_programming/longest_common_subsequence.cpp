//
// Created by Süleyman Karakaşoğlu on 10.07.2022.
//

#include <vector>
#include <string>

int dfs(std::string word1, std::string word2, int idx1 ,int idx2, std::vector<std::vector<int>>& memo) {
    if (idx1 >= word1.size() || idx2 >= word2.size()) return 0;
    if (memo[idx1][idx2] != 0) return memo[idx1][idx2];
    if (word1[idx1] == word2[idx2]) {
        return memo[idx1][idx2] = 1 + dfs(word1, word2, idx1 + 1, idx2 + 1, memo);
    } else {
        return memo[idx1][idx2] = std::max(dfs(word1, word2, idx1 + 1, idx2, memo), dfs(word1, word2, idx1, idx2 + 1, memo));
    }
}

int longest_common_subsequence(std::string word1, std::string word2) {
    std::vector<std::vector<int>> memo(word1.size(), std::vector<int>(word2.size(), 0));
    return dfs(word1, word2, 0, 0, memo);
}