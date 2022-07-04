//
// Created by Süleyman Karakaşoğlu on 4.07.2022.
//

#include <vector>

struct Coordinate{
    int x;
    int y;

    Coordinate(int x, int y) : x(x), y(y) {}
};

std::vector<Coordinate> getNeighbors(const Coordinate& coords, int m, int n) {
    int delta_row[4] = {-1, 0, 1, 0};
    int delta_col[4] = {0, 1, 0, -1};

    std::vector<Coordinate> res;
    for (auto i = 0; i < 4; i++) {
        auto x = coords.x + delta_col[i];
        auto y = coords.y + delta_row[i];

        if (x >= 0 && x < n && y>= 0 && y < m) {
            res.emplace_back(Coordinate(x, y));
        }
    }

    return res;
}

void dfs(std::vector<std::vector<int>>& visited, const Coordinate& coords, int prev_height, std::vector<std::vector<int>>& heights, int m, int n) {
    if (visited[coords.y][coords.x] != -1 || heights[coords.y][coords.x] < prev_height) return;

    auto neighbors = getNeighbors(coords, m, n);

    visited[coords.y][coords.x] = 1;
    for (const auto& neighbor: neighbors) {
        dfs( visited, neighbor, heights[coords.y][coords.x], heights, m, n);
    }
}

std::vector<std::vector<int>> pacificAtlantic(std::vector<std::vector<int>>& heights) {
    auto m = heights.size();
    auto n = heights[0].size();

    std::vector<std::vector<int>> atl(m, std::vector<int>(n, -1));
    std::vector<std::vector<int>> pac(m, std::vector<int>(n, -1));

    std::vector<std::vector<int>> res;
    for (auto i = 0; i < n; i++) {
        Coordinate pac_coords(i, 0);
        dfs(pac, pac_coords, heights[0][i], heights, m, n);

        Coordinate atl_coords(i, m - 1);
        dfs(atl, atl_coords, heights[m - 1][i], heights, m, n);
    }

    for (auto i = 0; i < m; i++) {
        Coordinate pac_coords(0, i);
        dfs(pac, pac_coords, heights[i][0], heights, m, n);

        Coordinate atl_coords(n - 1, i);
        dfs(atl, atl_coords, heights[i][n - 1], heights, m, n);
    }

    for (auto i = 0; i < m; i++) {
        for (auto j = 0; j < n; j++) {
            if (atl[i][j] != -1 && pac[i][j] != -1) {
                res.emplace_back(std::vector<int>{i, j});
            }
        }
    }

    return res;
}