//
// Created by Süleyman Karakaşoğlu on 24.06.2022.
//

#include <string>
#include <vector>
#include <unordered_map>

std::string get_minimum_window(std::string original, std::string check) {
    if (original.length() < check.length()) return "";

    std::unordered_map<int, int> check_list;
    std::unordered_map<int, int> window;
    std::string res;

    for (const auto& c: check) {
        check_list[c]++;
    }

    int l = 0, r = 0;

    auto min_length = std::numeric_limits<int>::max();
    while (l <= original.length() - check.length()) {
        bool contains = true;
        for (const auto& c: check_list) {
            auto window_it = window.find(c.first);
            if (window_it == window.end() ||window_it->second < c.second) {
                contains = false;
                break;
            }
        }

        if (!contains) {
            window[original[r]]++;
            r++;
        } else {
            if (r - l < min_length) {
                res = original.substr(l, r - l);
                min_length = r - l;
            } else if (r - l == min_length) {
                auto possible_res = original.substr(l, r - l);
                if (possible_res < res) {
                    res = possible_res;
                }
            }
            window[original[l]]--;
            l++;
        }
    }

    return res;
}