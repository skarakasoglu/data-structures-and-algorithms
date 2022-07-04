//
// Created by Süleyman Karakaşoğlu on 4.07.2022.
//

#include <vector>
#include <queue>

struct Coordinate{
    int x;
    int y;

    Coordinate(int x, int y) : x(x), y(y) {}
};

std::vector<Coordinate> getNeighbors(Coordinate coords, int m, int n) {
    int delta_row[4] = {-1, 0, 1, 0};
    int delta_col[4] = {0, 1, 0, -1};

    std::vector<Coordinate> res;
    for (auto i = 0; i < 4; i++) {
        auto x = coords.x + delta_col[i];
        auto y = coords.y + delta_row[i];

        if (x >= 0 && y >= 0 && x < m && y < n) {
            res.emplace_back(Coordinate(x, y));
        }
    }

    return res;
}

int maxAreaOfIsland(std::vector<std::vector<int>>& grid) {
    auto m = grid.size();
    auto n = grid[0].size();

    std::vector<std::vector<bool>> visited(m, std::vector<bool>(n, false));
    auto max_area = 0;

    for (auto i = 0; i < m; i++) {
        for (auto j = 0; j < n; j++) {
            if (visited[i][j] || grid[i][j] != 1) continue;

            auto start = Coordinate(i, j);
            visited[start.x][start.y] = true;
            auto area = 0;

            std::queue<Coordinate> queue;
            queue.push(start);

            while (!queue.empty()) {
                auto top = queue.front();
                auto neighbors = getNeighbors(top, m, n);

                for (const auto& neighbor: neighbors) {
                    if (visited[neighbor.x][neighbor.y] || grid[neighbor.x][neighbor.y] != 1) continue;

                    visited[neighbor.x][neighbor.y] = true;
                    queue.push(neighbor);
                }
                area++;
                queue.pop();
            }

            max_area = std::max(max_area, area);
        }
    }

    return max_area;
}