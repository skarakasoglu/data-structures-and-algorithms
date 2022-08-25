//
// Created by Süleyman Karakaşoğlu on 25.08.2022.
//
#include <queue>
using namespace std;


struct Coordinate{
    int row;
    int col;
};

vector<int> spiralTraverse(vector<vector<int>> array) {
    vector<int> res;

    int n = array.size();
    int m = array[0].size();
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    int current_direction = 1;
    auto get_next = [&](const Coordinate& current) -> Coordinate {
        int delta_row[4] = {-1, 0, 1, 0};
        int delta_col[4] = {0, 1, 0, -1};

        vector<Coordinate> neighbors(4, Coordinate{-1, -1});
        bool can_move = false;
        for (auto i = 0; i < 4; i++) {
            int row = current.row + delta_row[i];
            int col = current.col + delta_col[i];

            if ((row >= 0 && row < n && col >= 0 && col < m) && (!visited[row][col])) {
                neighbors[i] = Coordinate{row, col};
                can_move = true;
            }
        }

        if (!can_move) return Coordinate{-1, -1};

        auto possible_next = neighbors[current_direction];
        while (possible_next.row == -1 || visited[possible_next.row][possible_next.col]) {
            current_direction++;
            if (current_direction > 3) current_direction = 0;
            possible_next = neighbors[current_direction];
        }

        return possible_next;
    };

    std::queue<Coordinate> coords;
    coords.push(Coordinate{0, 0});
    visited[0][0] = true;

    while (!coords.empty()) {
        auto top = coords.front();
        res.emplace_back(array[top.row][top.col]);
        auto next = get_next(top);
        if (next.row != -1) {
            coords.push(next);
            visited[next.row][next.col] = true;
        }
        coords.pop();
    }

    return res;
}
