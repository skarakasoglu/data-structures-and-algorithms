//
// Created by Süleyman Karakaşoğlu on 5.07.2022.
//

#include <string>
#include <unordered_set>

int lengthOfLongestSubstring(std::string s) {
    std::unordered_set<char> existing_chars;

    auto i = 0;
    auto window = 0;

    auto longest_length = 0;
    while (window < s.length()) {
        if (!existing_chars.count(s[window])) {
            existing_chars.emplace(s[window]);
            window++;
            longest_length = std::max(longest_length, window - i);
        } else {
            existing_chars.erase(s[i]);
            i++;
        }
    }

    return longest_length;
}