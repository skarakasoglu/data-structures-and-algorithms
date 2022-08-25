//
// Created by Süleyman Karakaşoğlu on 25.08.2022.
//
#include <string>
#include <unordered_map>
using namespace std;

int firstNonRepeatingCharacter(string string) {

    std::unordered_map<char, int> occurrences;
    for (auto i = 0; i < string.size(); i++) {
        occurrences[string[i]]++;
    }

    for (auto i = 0; i < string.size(); i++) {
        if (occurrences[string[i]] == 1) return i;
    }

    return -1;
}
