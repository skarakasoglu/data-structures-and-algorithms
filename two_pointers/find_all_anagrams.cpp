//
// Created by Süleyman Karakaşoğlu on 24.06.2022.
//

#include <vector>
#include <string>
#include <unordered_map>

std::vector<int> find_all_anagrams(std::string original, std::string check) {
    std::unordered_map<char, int> character_counts;

    for (const auto& c: check) {
        character_counts[c]++;
    }

    int n = original.size();
    int l = 0, r = 0;
    std::unordered_map<char, int> window;
    std::vector<int> res;
    while (r < n) {
        if (r - l == check.size()) {
            bool is_anagram = true;
            for (const auto& c: check) {
                if (character_counts[c] != window[c]) {
                    is_anagram = false;
                    break;
                }
            }

            if (is_anagram) {
                res.emplace_back(l);
            }
            window[original[l]]--;
            l++;
        } else {
            window[original[r]]++;
            r++;
        }
    }

    return res;
}