//
// Created by Süleyman Karakaşoğlu on 18.06.2022.
//

#include <vector>
#include <queue>
#include <algorithm>
#include <unordered_set>

int shortest_path(std::vector<std::vector<int>> graph, int a, int b) {
    std::queue<int> queue;
    std::unordered_set<int> visited{false};

    queue.push(a);
    visited.emplace(a);
    int level = 0;

    while (queue.size() > 0) {
        int n = queue.size();

        for(auto i = 0; i < n; i++) {
            auto current = queue.front();
            if (current == b) return level;

            for(const auto& neighbor: graph[current]) {
                if (visited.count(neighbor)) {
                    continue;
                }

                queue.push(neighbor);
                visited.emplace(current);
            }

            queue.pop();
        }
        level++;
    }

    return level;
}

struct Coordinate{
    int x;
    int y;

    bool operator==(const Coordinate& coord) const {
        return (this->x == coord.x && this->y == coord.y);
    }

    struct HashFunction {
        size_t operator()(const Coordinate& coord) const {
            size_t r_hash = std::hash<int>()(coord.x);
            size_t c_hash = std::hash<int>()(coord.y);
            return r_hash ^ c_hash;
        }
    };
};

std::vector<Coordinate> get_neighbors_flood_fill(Coordinate coord, int previous_color, std::vector<std::vector<int>> image) {
    int delta_row[] = {-1, 0, 1, 0};
    int delta_col[] = {0, 1, 0, -1};

    std::vector<Coordinate> neighbors;
    for (auto i = 0; i < 4; i++) {
        auto neighbor_row = coord.x + delta_row[i];
        auto neighbor_col = coord.y + delta_col[i];

        if (0 <= neighbor_row && neighbor_row < image.size() &&
        0 <= neighbor_col && neighbor_col < image[0].size() &&
        image[neighbor_row][neighbor_col] == previous_color) {
            neighbors.emplace_back(Coordinate{neighbor_row, neighbor_col});
        }
    }

    return neighbors;
}

std::vector<std::vector<int>> flood_fill(int r, int c, int replacement, std::vector<std::vector<int>> image) {
    std::queue<Coordinate> queue;

    int rows = image.size();
    int cols = image[0].size();
    bool visited[rows][cols] = { {false} };

    auto first_vertex = Coordinate{r, c};
    auto previous_color = image[r][c];
    queue.push(first_vertex);
    image[r][c] = replacement;
    visited[r][c] = true;

    while (queue.size() > 0) {
        int n = queue.size();

        for (auto i = 0; i < n; i++) {
            auto current = queue.front();
            auto neighbors = get_neighbors_flood_fill(current, previous_color, image);

            for (const auto& neighbor: neighbors) {
                if (visited[neighbor.x][neighbor.y]) {
                    continue;
                }

                image[neighbor.x][neighbor.y] = replacement;
                queue.push(neighbor);
                visited[neighbor.x][neighbor.y] = true;
            }

            queue.pop();
        }
    };

    return image;
}

std::vector<Coordinate> get_neighbors_islands(int x, int y, int rows, int cols) {
    int delta_row[4] = {-1, 0, 1, 0};
    int delta_col[4] = {0, 1, 0, -1};

    std::vector<Coordinate> coords;
    for (auto i = 0; i < 4; i++) {
        auto row = x + delta_row[i];
        auto col = y + delta_col[i];

        if (row >= 0 && row < rows && col >= 0 && col < cols) {
            coords.emplace_back(Coordinate{row, col});
        }
    }

    return coords;
}

int count_number_of_islands(std::vector<std::vector<int>> grid) {

    int rows = grid.size(), cols = grid[0].size();
    int island_count = 0;

    for (auto i = 0; i < rows; i++) {
        for (auto j = 0; j < cols; j++) {
            if (grid[i][j] == 0) continue;

            auto coords = Coordinate{i, j};
            std::queue<Coordinate> queue;
            queue.push(coords);
            grid[i][j] = 0;

            while (queue.size() > 0) {
                auto current = queue.front();

                auto neighbors = get_neighbors_islands(current.x, current.y, rows, cols);
                for (const auto& neighbor: neighbors) {
                    if (grid[neighbor.x][neighbor.y] == 0) continue;

                    queue.push(neighbor);
                    grid[neighbor.x][neighbor.y] = 0;
                }

                queue.pop();
            }

            island_count++;
        }
    }

    return island_count;
}

std::vector<Coordinate> get_knight_neighbors(int x, int y, int rows, int cols) {
    int delta_rows[8] = {-1, -2, -2, -1, 1, 2, 2, 1};
    int delta_cols[8] = {-2, -1, 1, 2, 2, 1, -1, -2};

    std::vector<Coordinate> coords;
    for (auto i = 0; i < 8; i++) {
            auto row = x + delta_rows[i];
            auto col = y + delta_cols[i];

            coords.emplace_back(Coordinate{row, col});
    }
    return coords;
}

int get_knight_shortest_path(int x, int y) {
    int rows = x + 10;
    int cols = y + 10;

    int grid[rows][cols] = {0};

    Coordinate coord{0, 0};
    std::queue<Coordinate> queue;
    queue.push(coord);
    grid[coord.x][coord.y] = 1;

    int level = 0;
    while (queue.size() > 0) {
        int n = queue.size();

        for (auto i = 0; i < n; i++) {
            auto current = queue.front();
            if (current.x == x && current.y == y) return level;

            auto neighbors = get_knight_neighbors(current.x, current.y, rows, cols);
            for(const auto& neighbor: neighbors) {
                if (grid[neighbor.x][neighbor.y] == 1) continue;

                queue.push(neighbor);
                grid[neighbor.x][neighbor.y] = 1;
            }

            queue.pop();
        }
        level++;
    }

    return level;
}

std::vector<std::vector<int>> map_gate_distances(std::vector<std::vector<int>> dungeon_map) {
    int rows = dungeon_map.size();
    int cols = dungeon_map[0].size();

    auto get_neighbors = [&](int x, int y) -> std::vector<Coordinate> {
        int delta_rows[4] = {-1, 0, 1, 0};
        int delta_cols[4] = {0, 1, 0, -1};

        std::vector<Coordinate> coords;

        for (auto i = 0; i < 4; i++) {
            int row = x + delta_rows[i];
            int col = y + delta_cols[i];

            if (row >= 0 && row < rows && col >= 0 && col < cols && dungeon_map[row][col] == std::numeric_limits<int>::max()) {
                coords.emplace_back(Coordinate{row, col});
            }
        }

        return coords;
    };

    std::queue<Coordinate> queue;
    for (auto i = 0; i < rows; i++) {
        for (auto j = 0; j < cols; j++) {
            if (dungeon_map[i][j] == 0) queue.push(Coordinate{i, j});
        }
    }

    while (queue.size() > 0) {
        auto current = queue.front();
        auto neighbors = get_neighbors(current.x, current.y);

        for (const auto& neighbor: neighbors) {
            queue.push(neighbor);
            dungeon_map[neighbor.x][neighbor.y] = dungeon_map[current.x][current.y] + 1;
        }

        queue.pop();
    }

    return dungeon_map;
}