//
// Created by Süleyman Karakaşoğlu on 24.06.2022.
//

#include <string>
#include <unordered_set>

int longest_substring_without_repeating_characters(std::string s) {
    int n = s.size();
    int l = 0, r = 0;
    std::unordered_set<char> existing_chars;

    int longest = 0;
    while(r < n) {
        if (!existing_chars.count(s[r])) {
            existing_chars.emplace(s[r]);
            r++;
        } else {
            existing_chars.erase(s[l]);
            l++;
        }
        longest = std::max(longest, r - l);
    }

    return longest;
}