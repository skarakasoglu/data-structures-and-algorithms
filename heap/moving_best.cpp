//
// Created by Süleyman Karakaşoğlu on 24.06.2022.
//

#include <string>
#include <queue>
#include <unordered_set>

std::string reorganize_string(std::string s) {
    int n = s.length();
    std::unordered_map<char, int> character_counts;

    for (const auto& c: s) {
        character_counts[c]++;
    }

    auto compare_chars = [](const std::pair<char, int>& p1, const std::pair<char, int>& p2) -> bool {
        return p1.second < p2.second;
    };
    std::priority_queue<std::pair<char, int>, std::vector<std::pair<char, int>>, decltype(compare_chars)> heap(character_counts.begin(), character_counts.end(), compare_chars);
    if (heap.top().second > (n + 1) / 2) return "";

    int ptr = 0;
    std::vector<char> res(n);
    while (!heap.empty()) {
        auto cur = heap.top();
        heap.pop();

        for (auto i = 0; i < cur.second; i++) {
            res[ptr] = cur.first;
            ptr += 2;

            if (ptr >= n) ptr = 1;
        }
    }

    return {res.begin(), res.end()};
}

int nth_ugly_number(int n) {
    std::priority_queue<int, std::vector<int>, std::greater<>> heap;
    std::unordered_set<int> used_nums;

    std::vector<int> allowed_primes = {2, 3, 5};
    heap.push(1);
    used_nums.emplace(1);
    for (auto k = 0; k < n - 1; k++) {
        auto res = heap.top();
        heap.pop();
        for (auto j = 0; j < allowed_primes.size(); j++) {
            auto num = res * allowed_primes[j];
            if (!used_nums.count(num)) {
                heap.push(num);
                used_nums.emplace(num);
            }
        }
    }

    return heap.top();
}