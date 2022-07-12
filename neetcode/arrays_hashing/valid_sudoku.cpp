//
// Created by Süleyman Karakaşoğlu on 12.07.2022.
//

#include <vector>
#include <unordered_set>

bool isValidSudoku(std::vector<std::vector<char>>& board) {
    int m = board.size(), n = board[0].size();
    std::vector<std::unordered_set<char>> row_digits(m);
    std::vector<std::unordered_set<char>> col_digits(n);
    std::vector<std::vector<std::unordered_set<char>>> sub_box_digits(3, std::vector<std::unordered_set<char>>(3));

    for (auto i = 0; i < m; i++) {
        for (auto j = 0; j < n; j++) {
            if (board[i][j] == '.') continue;

            if (row_digits[i].count(board[i][j])) return false;
            row_digits[i].emplace(board[i][j]);

            if (col_digits[j].count(board[i][j])) return false;
            col_digits[j].emplace(board[i][j]);

            if (sub_box_digits[i / 3][j / 3].count(board[i][j])) return false;
            sub_box_digits[i / 3][j / 3].emplace(board[i][j]);
        }
    }

    return true;
}