//
// Created by Süleyman Karakaşoğlu on 25.06.2022.
//

#include <vector>
#include <string>
#include <unordered_map>

std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string>& strs) {
    std::unordered_map<std::string, std::vector<std::string>> anagram_groups;

    for (auto i = 0; i < strs.size(); i++) {
        auto s = strs[i];
        std::sort(s.begin(), s.end());
        anagram_groups[s].emplace_back(strs[i]);
    }

    std::vector<std::vector<std::string>> res;
    for (const auto& group: anagram_groups) {
        res.emplace_back(group.second);
    }

    return res;
}