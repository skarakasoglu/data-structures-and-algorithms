//
// Created by Süleyman Karakaşoğlu on 20.06.2022.
//

#include <queue>
#include <string>
#include <unordered_map>

std::vector<std::string> task_scheduling(std::vector<std::string> tasks, std::vector<std::vector<std::string>> requirements) {
    std::unordered_map<std::string, int> parent_counts;

    for (auto requirement: requirements) {
        parent_counts[requirement[1]]++;
    }

    auto get_children = [&](std::string parent) -> std::vector<std::string> {
        std::vector<std::string> res;
        for (auto requirement: requirements) {
            if (requirement[0] != parent) continue;

            res.emplace_back(requirement[1]);
        }
        return res;
    };

    std::queue<std::string> task_queue;
    for (auto task: tasks) {
        if (parent_counts[task] == 0) {
            task_queue.push(task);
        }
    }

    std::vector<std::string> res;
    while (!task_queue.empty()) {
        auto top_task = task_queue.front();
        auto task_children = get_children(top_task);

        res.emplace_back(top_task);
        for (const auto& child: task_children) {
            parent_counts[child]--;

            if (parent_counts[child] == 0) task_queue.push(child);
        }

        task_queue.pop();
    }

    return res;
}

bool sequence_reconstruction(std::vector<int> original, std::vector<std::vector<int>> seqs) {
    std::unordered_map<int, int> parent_count;

    for (const auto& elem: seqs) {
        for (auto i = 1; i < elem.size(); i++) {
            parent_count[elem[i]]++;
        }
    }

    auto get_children = [&](int parent) -> std::vector<int> {
        std::vector<int> res;
        for (const auto& elem: seqs) {

            for (auto i = 0; i < elem.size(); i++) {
                if (elem[i] == parent && i < elem.size() - 1) {
                    res.emplace_back(elem[i + 1]);
                }
            }
        }

        return res;
    };

    std::queue<int> queue;

    for (const auto& elem: original) {
        if (parent_count[elem] == 0) queue.push(elem);
    }

    if (queue.empty()) return false;

    int i = 0;
    while (!queue.empty()) {
        auto top = queue.front();
        auto children = get_children(top);
        if (original[i] != top) {
            return false;
        }

        int possible_next_elem_count = 0;
        for (const auto& child: children) {
            parent_count[child]--;

            if (parent_count[child] == 0) {
                queue.push(child);
                possible_next_elem_count++;
            }
        }

        i++;
        if (possible_next_elem_count > 1) {
            return false;
        }

        queue.pop();
    }

    return true;
}

int task_scheduling_2(std::vector<std::string> tasks, std::vector<int> times, std::vector<std::vector<std::string>> requirements) {
    std::unordered_map<std::string, int> parent_count;
    std::unordered_map<std::string, int> task_times;

    for (const auto& req: requirements) {
        parent_count[req[1]]++;
    }

    for (auto i = 0; i < tasks.size(); i++) {
        task_times[tasks[i]] = times[i];
    }

    auto get_children = [&](std::string parent) -> std::vector<std::string> {
        std::vector<std::string> res;
        for (const auto& req: requirements) {
            if (req[0] == parent) {
                res.emplace_back(req[1]);
            }
        }

        return res;
    };

    std::queue<std::string> task_queue;
    int time_amount = 0;
    for (const auto& task: tasks) {
        if (parent_count[task] == 0)  {
            task_queue.push(task);

            time_amount = std::max(time_amount, task_times[task]);
        }
    }

    while (!task_queue.empty()) {
        auto top_task = task_queue.front();
        auto children = get_children(top_task);

        int max_time_next_queue;
        for (const auto& child: children) {
            parent_count[child]--;

            if (parent_count[child] == 0) {
                task_queue.push(child);
                max_time_next_queue = std::max(max_time_next_queue, task_times[child]);
            }
        }

        time_amount += max_time_next_queue;
        task_queue.pop();
    }

    return time_amount;
}

bool valid_course_dfs(std::unordered_map<int, std::vector<int>>& graph, std::unordered_map<int, int>& visited_state, int current_vertex) {
    visited_state[current_vertex] = 1;
    auto children = graph[current_vertex];
    for (const auto& child: children) {
        if (visited_state[child] == 2) continue;
        if (visited_state[child] == 1) return false;
        if (!valid_course_dfs(graph, visited_state, child)) return false;
    }
    visited_state[current_vertex] = 2;

    return true;
}

bool is_valid_course_schedule(int n, std::vector<std::vector<int>> prerequisites) {
    std::unordered_map<int, std::vector<int>> graph;
    std::unordered_map<int, int> visited_state;


    for (const auto& prerequisite: prerequisites) {
        graph[prerequisite[1]].emplace_back(prerequisite[0]);
    }


    return valid_course_dfs(graph, visited_state, prerequisites[0][1]);
}