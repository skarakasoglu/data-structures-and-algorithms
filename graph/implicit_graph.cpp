//
// Created by Süleyman Karakaşoğlu on 20.06.2022.
//

#include <vector>
#include <string>
#include <queue>
#include <unordered_map>
#include <unordered_set>

int num_steps(std::string target_combo, std::vector<std::string> trapped_combos) {
    std::unordered_map<char, char> next_digit = {
            {'0', '1'},
            {'1', '2'},
            {'2', '3'},
            {'3', '4'},
            {'4', '5'},
            {'5', '6'},
            {'6', '7'},
            {'7', '8'},
            {'8', '9'},
            {'9', '0'},
    };

    std::unordered_map<char, char> prev_digit = {
            {'0', '9'},
            {'1', '0'},
            {'2', '1'},
            {'3', '2'},
            {'4', '3'},
            {'5', '4'},
            {'6', '5'},
            {'7', '6'},
            {'8', '7'},
            {'9', '8'},
    };

    std::unordered_set<std::string> trapped_combos_set(trapped_combos.begin(), trapped_combos.end());
    std::unordered_map<std::string, int> steps;
    steps["0000"] = 0;

    std::queue<std::string> queue;
    queue.push("0000");

    while (queue.size() > 0) {
        auto current = queue.front();

        for (auto i = 0; i < 4; i++) {
            auto next = current.substr(0, i) + next_digit[current[i]] + current.substr(i + 1);
            if (!trapped_combos_set.count(next) && !steps.count(next)) {
                queue.push(next);
                steps[next] = steps[current] + 1;

                if (next == target_combo) return steps[next];
            }

            auto prev = current.substr(0, i) + prev_digit[current[i]] + current.substr(i + 1);
            if (!trapped_combos_set.count(prev) && !steps.count(prev)) {
                queue.push(prev);
                steps[prev] = steps[current] + 1;

                if (prev == target_combo) return steps[prev];
            }
        }

        queue.pop();
    }

    return -1;
}

int word_ladder(std::string begin, std::string end, std::vector<std::string> word_list) {

    std::string alphabet = "abcdefghijklmnopqrstuvwxyz";
    std::unordered_set<std::string> word_set(word_list.begin(), word_list.end());

    std::queue<std::string> queue;
    queue.push(begin);

    std::unordered_map<std::string, int> steps;
    steps[begin] = 0;

    while (queue.size() > 0) {
        auto current = queue.front();
        for (auto i = 0; i < current.size(); i++) {
            for (auto j = 0; j < alphabet.size(); j++) {
                if (current[i] == alphabet[j]) continue;

                auto temp = current.substr(0, i) + alphabet[j] + current.substr(i + 1);
                if (word_set.count(temp) && !steps.count(temp)) {
                    queue.push(temp);
                    steps[temp] = steps[current] + 1;

                    if (temp == end) return steps[temp];
                }
            }
        }

        queue.pop();
    }
}

struct Coordinate {
    int x;
    int y;
};

int num_steps(std::vector<std::vector<int>> init_pos) {
    int rows = init_pos.size();
    int cols = init_pos[0].size();

    int target_state = 123450;
    int row_directions[4] = {1, 0, -1, 0};
    int col_directions[4] = {0, 1,0, -1};

    auto serialize = [](std::vector<std::vector<int>> position) -> int {
        int total = 0;
        for(auto line: position) {
            for (auto entry: line) {
                total *= 10;
                total += entry;
            }
        }

        return total;
    };

    auto deserialize = [](int state) -> std::vector<std::vector<int>> {
        std::vector<std::vector<int>> result(2);
        for (int i = 1; i >= 0; i--) {
            for (int j = 2; j >= 0; j--) {
                int exponent = i * 3 + j;
                int digit = state / (int) (std::round(std::pow(10, exponent))) % 10;
                result[1 - i].emplace_back(digit);
            }
        }

        return result;
    };

    int init_state = serialize(init_pos);
    if (init_state == target_state) return 0;
    std::unordered_map<int, int> moves_map({{init_state, 0}});
    std::queue<int> moves_queue;
    moves_queue.push(init_state);

    while (moves_queue.size() > 0) {
        int state = moves_queue.front();

        int row, col = 0;
        std::vector<std::vector<int>> pos = deserialize(state);
        for (auto i = 0; i < rows; i++) {
            for (auto j = 0; j < cols; j++) {
                if (pos[i][j] == 0) {
                    row = i;
                    col = j;
                }
            }
        }

        for (auto i = 0; i < 4; i++) {
            int new_row = row + row_directions[i], new_col = col + col_directions[i];
            if (new_row >= 0 && new_row < rows && new_col >= 0 && new_col < cols) {
                auto new_pos = deserialize(state);
                new_pos[row][col] = pos[new_row][new_col];
                new_pos[new_row][new_col] = pos[row][col];
                auto new_state = serialize(new_pos);
                if (!moves_map.count(new_state)) {
                    moves_queue.push(new_state);
                    moves_map[new_state] = moves_map[state] + 1;

                    if (new_state == target_state) return moves_map[new_state];
                }
            }
        }

        moves_queue.pop();
    }

    return -1;
}