//
// Created by Süleyman Karakaşoğlu on 5.07.2022.
//

#include <string>
#include <unordered_map>

int characterReplacement(std::string s, int k) {
    std::unordered_map<char, int> count;
    using pair_type = decltype(count)::value_type;
    auto res = 0;

    auto l = 0;

    for (auto r = 0; r < s.length(); r++) {
        count[s[r]]++;

        while ((r - l + 1) - std::max_element(count.begin(), count.end(), [&](const pair_type& p1, const pair_type& p2) {
            return p1.second < p2.second;
        })->second > k) {
            count[s[l]]--;
            l++;
        }

        res = std::max(res, r - l + 1);
    }

    return res;
}