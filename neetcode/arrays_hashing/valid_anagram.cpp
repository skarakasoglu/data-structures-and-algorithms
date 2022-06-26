//
// Created by Süleyman Karakaşoğlu on 21.06.2022.
//

#include <string>
#include <unordered_map>

bool isAnagram(std::string s, std::string t) {
    if (t.size() != s.size()) return false;

    std::unordered_map<char, int> word_char_counts;
    std::unordered_map<char, int> anagram_word_counts;

    for (auto i = 0; i < s.size(); i++) {
        word_char_counts[s[i]]++;
        anagram_word_counts[t[i]]++;
    }

    for (auto chr: word_char_counts) {
        if (anagram_word_counts[chr.first] != chr.second) return false;
    }

    return true;
}