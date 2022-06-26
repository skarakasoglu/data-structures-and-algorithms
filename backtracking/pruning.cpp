//
// Created by Süleyman Karakaşoğlu on 17.06.2022.
//

#include <vector>
#include <string>

bool is_palindrome(std::string s) {
    int i = 0, j = s.size() - 1;
    while (i <= j) {
        if (s[i] != s[j]) return false;

        i++;
        j--;
    }

    return true;
}

void dfs_partition(std::vector<std::vector<std::string>>& res, std::vector<std::string> part, std::string s, int start) {
    if (start == s.size()) {
        std::vector<std::string> li(part);
        res.emplace_back(li);
    }

    for (auto i = start; i < s.size(); i++) {
        if (is_palindrome(s.substr(start, i + 1 - start))) {
            part.emplace_back(s.substr(start, i + 1 -start));
            dfs_partition(res, part, s, i + 1);
            part.pop_back();
        }
    }
}

std::vector<std::vector<std::string>> partition(std::string s) {
    std::vector<std::vector<std::string>> res;
    dfs_partition(res, {}, s, 0);
    return res;
}