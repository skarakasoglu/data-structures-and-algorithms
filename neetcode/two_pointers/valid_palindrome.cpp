//
// Created by Süleyman Karakaşoğlu on 21.06.2022.
//

#include <string>

bool isPalindrome(std::string s) {
    s.erase(std::remove_if(s.begin(), s.end(), [](char a) -> bool {
            return !std::isalnum(a);
    }), s.end());
    std::transform(s.begin(), s.end(), s.begin(), [](char c) { return std::tolower(c); });

    int i = 0, j = s.size() - 1;

    while (i <= j) {
        if (s[i] != s[j]) return false;

        i++;
        j--;
    }

    return true;
}