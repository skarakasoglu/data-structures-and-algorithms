//
// Created by Süleyman Karakaşoğlu on 17.06.2022.
//

#include <vector>
#include <string>

bool dfs(int start_index, int memo[], std::string s, std::vector<std::string> words) {
    if (start_index == s.size()) return true;
    if (memo[start_index] != -1) return memo[start_index] == 1;
    int ok = 0;

    for (std::string word: words) {
        if (s.substr(start_index).find(word) == 0) {
            if (dfs(start_index + word.size(), memo, s, words)) {
                ok = 1;
                break;
            }
        }
    }

    memo[start_index] = ok;
    return ok == 1;
}

bool word_break(std::string s, std::vector<std::string> words) {
    int memo[s.size()];
    std::fill_n(memo, s.size(), - 1);
    return dfs(0, memo, s, words);
}

int decode_dfs(int start_index, std::string digits, std::string letters[26]) {
    if (start_index == digits.length()) return 1;

    int ways = 0;
    std::string remaining = digits.substr(start_index);
    for (auto i = 0; i < 26; i++) {
        std::string prefix = letters[i];
        if (remaining.find(prefix) == 0) {
            ways += decode_dfs(start_index + prefix.length(), digits, letters);
        }
    }

    return ways;
}

int decode_ways(std::string digits) {
    std::string letters[26];

    for (auto i = 0; i < 26;i++) {
        letters[i] = std::to_string(i + 1);
    }

    return decode_dfs(0, digits, letters);
}