//
// Created by Süleyman Karakaşoğlu on 10.07.2022.
//

#include <string>
#include <vector>

int dfs(std::string word1, int m, std::string word2, int n) {
    if (m == 0) return n;
    if (n == 0) return m;

    int cost = (word1[m - 1] == word2[n - 1]) ? 0 : 1;
    return std::min({dfs(word1, m - 1, word2, n) + 1, dfs(word1, m, word2, n - 1) + 1, dfs(word1, m - 1, word2, n - 1) + cost});
}

int min_distance(std::string word1, std::string word2) {
    return dfs(word1, word1.size(), word2, word2.size());
}