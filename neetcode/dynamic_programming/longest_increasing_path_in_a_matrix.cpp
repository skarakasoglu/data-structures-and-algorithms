//
// Created by Süleyman Karakaşoğlu on 26.06.2022.
//

#include <vector>

int dfs(int i, int j, std::vector<std::vector<int>>& memo, std::vector<std::vector<int>>& matrix) {
    if (memo[i][j] > std::numeric_limits<int>::min()) return memo[i][j];

    int rows = matrix.size();
    int cols = matrix[0].size();

    auto get_neighbors = [&]()-> std::vector<std::vector<int>> {
        int delta_row[4] = {-1, 0, 1, 0};
        int delta_col[4] = {0, 1, 0, -1};

        std::vector<std::vector<int>> res;
        for (auto k = 0; k < 4; k++) {
            auto x = i + delta_row[k];
            auto y = j + delta_col[k];

            if (x >= 0 && x < rows && y >= 0 && y < cols) {
                res.emplace_back(std::vector<int>{x, y});
            }
        }

        return res;
    };

    int longest_path = 1;
    auto neighbors = get_neighbors();
    for (const auto& neighbor:  neighbors) {
        if (matrix[neighbor[0]][neighbor[1]] <= matrix[i][j]) continue;

        longest_path = std::max(longest_path, dfs(neighbor[0], neighbor[1], memo, matrix) + 1);
    }

    memo[i][j] = longest_path;
    return longest_path;
}

int longestIncreasingPath(std::vector<std::vector<int>>& matrix) {
    int rows = matrix.size();
    int cols = matrix[0].size();

    std::vector<std::vector<int>> memo(rows, std::vector<int>(cols, std::numeric_limits<int>::min()));

    int longest_path = std::numeric_limits<int>::min();
    for (auto i = 0; i < rows; i++) {
        for (auto j = 0; j < cols; j++) {
            longest_path = std::max(longest_path, dfs(i, j, memo, matrix));
        }
    }

    return longest_path;
}