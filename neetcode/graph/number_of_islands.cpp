//
// Created by Süleyman Karakaşoğlu on 26.06.2022.
//

#include <vector>
#include <queue>
#include <unordered_set>

struct Coordinate{
    int x;
    int y;
};

int numIslands(std::vector<std::vector<char>>& grid) {
    int rows = grid.size();
    int cols = grid[0].size();

    auto get_neighbours = [&](const Coordinate& coords) -> std::vector<Coordinate> {
        int delta_row[4] = {-1, 0, 1, 0};
        int delta_col[4] = {0, 1, 0, -1};

        std::vector<Coordinate> res;
        for (auto i = 0; i < 4; i++) {
            auto x = coords.x + delta_col[i];
            auto y = coords.y + delta_row[i];

            if (x >= 0 && x < rows && y >= 0 && y < cols) {
                res.emplace_back(Coordinate{x, y});
            }
        }

        return res;
    };

    std::vector<std::vector<bool>> visited(rows, std::vector<bool>(cols, false));

    auto bfs = [&](const Coordinate& coords) {
        std::queue<Coordinate> queue;
        queue.push(coords);
        visited[coords.x][coords.y] = true;

        while (!queue.empty()) {
            auto top = queue.front();
            auto neighbours = get_neighbours(top);
            for (const auto& neighbour: neighbours) {
                if (visited[neighbour.x][neighbour.y] || grid[neighbour.x][neighbour.y] == '0') continue;

                queue.push(neighbour);
                visited[neighbour.x][neighbour.y] = true;
            }

            queue.pop();
        }
    };


    int island_count = 0;
    for (auto i = 0; i < rows; i++) {
        for (auto j = 0; j < cols; j++) {
            if (visited[i][j] || grid[i][j] != '1') continue;
            auto current_coords = Coordinate{i, j};
            bfs(current_coords);
            island_count++;
        }
    }

    return island_count;
}